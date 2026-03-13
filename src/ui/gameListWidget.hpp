#pragma once
#include <QMainWindow>
#include <QVBoxLayout>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qpushbutton.h>
#include "domain/game.hpp"
#include "domain/gameLibrary.hpp"

namespace UI {
	class GameListWidget : public QWidget
	{
		Q_OBJECT
	public:
		explicit GameListWidget(QWidget* parent = nullptr);

		void launchgameSelected(const std::string id);
		void removeGameSelected(const std::string id);
		void gameSelected(const std::string id);
		
		void updateGames(const std::vector<Domain::Game>& games);

	private:
		QVBoxLayout* mainLayout;
		std::vector<Domain::Game> m_GameList;
	};
}