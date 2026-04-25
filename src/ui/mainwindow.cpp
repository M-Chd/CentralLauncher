#include "mainwindow.hpp"

UI::MainWindow::MainWindow(App::Application* app,QWidget* parent) :
	QMainWindow(parent), application(app)
{
	setUpUI();
	setupConnections();
	refreshGameList();
}

void UI::MainWindow::setUpUI()
{
	this->setFixedSize(1280, 720);

	QWidget* central = new QWidget(this);
	QHBoxLayout* mainLayout = new QHBoxLayout;

	m_gameList = new GameListWidget(this);
	m_gameList->setMaximumWidth(300);
	m_gameList->setMaximumHeight(610);

	m_addGameBtn = new QPushButton("Add Game", this);
	m_addGameBtn->setGeometry(QRect(QPoint(5, 660), QSize(300, 35)));

	QWidget* infoPanel = new QWidget(this);
	QVBoxLayout* infoLayout = new QVBoxLayout;

	m_titleLabel = new QLabel("Select a game");
	m_categoryLabel = new QLabel("Category: -");
	m_pathLabel = new QLabel("Path: -");
	m_playButton = new QPushButton("Play");

	m_playButton->setMinimumHeight(40);

	infoLayout->addWidget(m_titleLabel);
	infoLayout->addWidget(m_categoryLabel);
	infoLayout->addWidget(m_pathLabel);
	infoLayout->addStretch();
	infoLayout->addWidget(m_playButton);

	infoPanel->setLayout(infoLayout);

	mainLayout->addWidget(m_gameList);
	mainLayout->addWidget(infoPanel);

	central->setLayout(mainLayout);
	this->setCentralWidget(central);

}

void UI::MainWindow::setupConnections()
{
	connect(m_addGameBtn, &QPushButton::released, this, &MainWindow::AddGameButton);
	connect(m_gameList->getListWidget(), &QListWidget::itemClicked, this, &MainWindow::onGameSelected);
	connect(m_gameList->getListWidget(), &QListWidget::itemDoubleClicked,
		this, &MainWindow::onGameDoubleClicked);

	connect(m_playButton, &QPushButton::clicked, [this]() {
		if (!m_selectedGameId.empty()) {
			application->launchgame(m_selectedGameId);
		}
		});
}

void UI::MainWindow::refreshGameList()
{
	m_gameList->updateGames(application->getLibrary());
}


void UI::MainWindow::AddGameButton()
{
	QString filepath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All files (*)"));

	if (filepath.isEmpty()) return;

	QDialog dialog;

	dialog.setWindowTitle("Game info");

	QLineEdit* nameEdit = new QLineEdit;
	QLineEdit* categoryEdit = new QLineEdit;

	QLabel* nameLabel = new QLabel("Game Name: ");
	QLabel* categoryLabel = new QLabel("Category of the game: ");

	QVBoxLayout* mainLayout = new QVBoxLayout;

	QHBoxLayout* nameLayout = new QHBoxLayout;
	nameLayout->addWidget(nameLabel);
	nameLayout->addWidget(nameEdit);

	QHBoxLayout* categoryLayout = new QHBoxLayout;
	categoryLayout->addWidget(categoryLabel);
	categoryLayout->addWidget(categoryEdit);

	QPushButton* okButton = new QPushButton("OK");
	QPushButton* cancelButton = new QPushButton("Cancel");

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(okButton);
	buttonLayout->addWidget(cancelButton);

	mainLayout->addLayout(nameLayout);
	mainLayout->addLayout(categoryLayout);
	mainLayout->addLayout(buttonLayout);

	dialog.setLayout(mainLayout);

	QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
	QObject::connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

	if (dialog.exec() == QDialog::Accepted) {
		QString gameName = nameEdit->text();
		QString gameCategory = categoryEdit->text();

		application->addGame(filepath.toStdString(), gameName.toStdString(), gameCategory.toStdString());
		refreshGameList();
	}
}

void UI::MainWindow::onGameSelected(QListWidgetItem* item)
{
	QString id = item->data(Qt::UserRole).toString();

	auto game = application->getGameById(id.toStdString());

	m_titleLabel->setText(QString::fromStdString(game.getName()));
	m_categoryLabel->setText("Category: " + QString::fromStdString(game.getCategory()));
	m_pathLabel->setText("Path: " + QString::fromStdString(game.getGamePath()));
}

void UI::MainWindow::onGameDoubleClicked(QListWidgetItem* item)
{
	QString id = item->data(Qt::UserRole).toString();

	auto game = application->getGameById(id.toStdString());

	application->launchgame(game.getId());
}


