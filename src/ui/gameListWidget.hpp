#pragma once
#include <QMainWindow>
#include <QListWidget>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <QVboxLayout>
#include <qpushbutton.h>
#include "domain/game.hpp"
#include "domain/gameLibrary.hpp"

namespace UI {
	class GameListWidget : public QWidget
	{
		Q_OBJECT
	public:
		explicit GameListWidget(QWidget* parent = nullptr);

		void addGame();
		void removeGame();
		void clearGames(); 

		QListWidget* getListWidget() const;
		void updateGames(const std::vector<Domain::Game>& games);

	private:
		void createItemFromGame(const Domain::Game& g);
		void extractGameIdFromItem();

	private:
		QListWidget* listWidget;
		QVBoxLayout* layout;
	};
}