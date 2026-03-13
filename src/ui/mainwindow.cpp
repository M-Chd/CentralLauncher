#include "mainwindow.hpp"

UI::MainWindow::MainWindow(App::Application* app,QWidget* parent) :
	QMainWindow(parent), application(app)
{
	this->setFixedSize(800, 600); //480p 

	m_btn = new QPushButton("Test", this);
	m_btn->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

	connect(m_btn, &QPushButton::released, this, &MainWindow::handleButton);

	//GameListWidget* listWidget = new GameListWidget(this);
	//this->setCentralWidget(listWidget);
}

/*
* Test QT function
*/
void UI::MainWindow::handleButton()
{
	m_btn->setText("Clic");
	m_btn->resize(100, 100);
	std::cout << "Hello" << "\n";
}

void UI::MainWindow::handleAddGame()
{

}

void UI::MainWindow::handleSearchGame()
{

}

