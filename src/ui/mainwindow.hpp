#pragma once
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qfiledialog.h>
#include <qlineedit.h>
#include "app/application.hpp"
#include "gameListWidget.hpp"

namespace UI {

	class MainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		explicit MainWindow(App::Application* app, QWidget* parent = nullptr);

		void handleButton(); //test
		void onAddGameClicked();
		void onGameSelected(const std::string gameId);
		void onGameDoubleClicked(std::string gameId);

	private:
		void setUpUI();
		void setupConnections();
		void refreshGameList();


	private:
		GameListWidget* m_gameList;
		App::Application* application;
		QPushButton* m_addGameBtn;
	};
}