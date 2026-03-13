#include "gameListWidget.hpp"

UI::GameListWidget::GameListWidget(QWidget* parent) : QWidget(parent)
{
	mainLayout = new QVBoxLayout(this);

	QLabel* title = new QLabel("Ma Liste de Jeux", this);
	mainLayout->addWidget(title);

	QPushButton* addBtn = new QPushButton("Add Game", this);
	addBtn->move(200, 650);

}

void UI::GameListWidget::launchgameSelected(const std::string id)
{

}

void UI::GameListWidget::removeGameSelected(const std::string id)
{
	if (!m_GameList.empty())
	{
		for (auto it = m_GameList.begin(); it != m_GameList.end(); it++)
		{
			if (it->getId() == id)
			{
				m_GameList.erase(it);
			}
		}
	}
}

void UI::GameListWidget::gameSelected(const std::string id)
{

}

void UI::GameListWidget::updateGames(const std::vector<Domain::Game>& games)
{
	for (auto& g : games) { m_GameList.emplace_back(g);}
}

