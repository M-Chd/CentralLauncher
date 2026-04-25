#pragma once
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qdialog.h>
#include <qfiledialog.h>
#include <qlineedit.h>
#include <qinputdialog.h>
#include "app/application.hpp"
#include "gameListWidget.hpp"

namespace UI {

	class MainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		explicit MainWindow(App::Application* app, QWidget* parent = nullptr);

		void AddGameButton();
		void onGameSelected(QListWidgetItem* item);
		void onGameDoubleClicked(QListWidgetItem* item);

	private:
		void setUpUI();
		void setupConnections();
		void refreshGameList();

	private:
		GameListWidget* m_gameList;
		App::Application* application;
		QPushButton* m_addGameBtn;
		QLabel* m_titleLabel;
		QLabel* m_categoryLabel;
		QLabel* m_pathLabel;
		QPushButton* m_playButton;
		std::string m_selectedGameId;
	};
}