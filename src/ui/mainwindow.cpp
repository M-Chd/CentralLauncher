#include "mainwindow.hpp"

UI::MainWindow::MainWindow(App::Application* app,QWidget* parent) :
	QMainWindow(parent), application(app)
{
	setUpUI();
	refreshGameList();
}

void UI::MainWindow::setUpUI()
{
	this->setFixedSize(1280, 720); //720p 
	m_addGameBtn = new QPushButton("Test", this);
	m_addGameBtn->setGeometry(QRect(QPoint(300, 300), QSize(200, 50)));

	connect(m_addGameBtn, &QPushButton::released, this, &MainWindow::handleButton);

	m_gameList = new GameListWidget(this);
	this->setCentralWidget(m_gameList);
	m_gameList->setMaximumSize(QSize(300,1000));
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
	m_addGameBtn->setText("Clic");
	m_addGameBtn->resize(100, 100);
	std::cout << "Hello" << "\n";
}


