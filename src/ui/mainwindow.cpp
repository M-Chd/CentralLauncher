#include "mainwindow.hpp"

UI::MainWindow::MainWindow(App::Application* app,QWidget* parent) :
	QMainWindow(parent), application(app)
{
	this->setFixedSize(1280, 720); // 720p
	QPushButton* btn = new QPushButton("test QT", this);
	btn->move(150, 130);

	GameListWidget* listWidget = new GameListWidget(this);
	this->setCentralWidget(listWidget);
}

