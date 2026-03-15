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
	this->setFixedSize(1280, 720); //720p 
	m_addGameBtn = new QPushButton("add Game", this);
	m_addGameBtn->setGeometry(QRect(QPoint(5,660), QSize(300, 45)));

	m_gameList = new GameListWidget(this);
	this->setCentralWidget(m_gameList);
	m_gameList->setMaximumSize(QSize(300,650));

	QPushButton* btntest = new QPushButton("TEST", this);
	btntest->setGeometry(QRect(QPoint(300, 300), QSize(100, 100)));

}

void UI::MainWindow::setupConnections()
{
	connect(m_addGameBtn, &QPushButton::released, this, &MainWindow::handleButton);
}

void UI::MainWindow::refreshGameList()
{
	m_gameList->updateGames(application->getLibrary());
}

/*
* Test QT function
*/
void UI::MainWindow::handleButton()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("All files (*)"));
	std::cout << "Hello" << "\n";
}


