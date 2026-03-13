#pragma once
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>
#include "app/application.hpp"
#include "gameListWidget.hpp"

namespace UI {

	class MainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		explicit MainWindow(App::Application* app, QWidget* parent = nullptr);

		void handleButton(); //test
		void handleAddGame();
		void handleSearchGame();


	private:
		App::Application* application;
		QPushButton* m_btn;
	};
}