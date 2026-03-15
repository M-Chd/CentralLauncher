#include "gameListWidget.hpp"

UI::GameListWidget::GameListWidget(QWidget* parent) : QWidget(parent)
{
	listWidget = new QListWidget(this);
	layout = new QVBoxLayout(this);
	layout->addWidget(listWidget);
}


void UI::GameListWidget::createItemFromGame(const Domain::Game& g)
{
	new QListWidgetItem(g.getName().c_str(), listWidget);
}

void UI::GameListWidget::clearGames()
{
	this->listWidget->clear();
}

QListWidget* UI::GameListWidget::getListWidget() const
{
	return listWidget;
}

void UI::GameListWidget::updateGames(const std::vector<Domain::Game>& games)
{
	clearGames();

	auto it = games.begin();
	while (it != games.end())
	{
		createItemFromGame(*it);
		it++;
	}
		
}

