#include <QApplication>
#include "ui/mainwindow.hpp"
#include "app/application.hpp"

int main(int argc,char *argv[])
{
	QApplication qtApp(argc, argv);
	
	App::Application app;
	UI::MainWindow window(&app);
	window.show();

	return qtApp.exec();
}