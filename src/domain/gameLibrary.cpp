#include "gameLibrary.hpp"

using namespace Domain;

void GameLibrary::loadGames(const std::vector<Game>& l_games)
{
    if (!l_games.empty())
    {
        for (auto &g : l_games)
        {
            games.push_back(g);
        }
    }
    else
    {
        /*Debug*/
        std::cout << "No games are loaded..." << "\n";
        LOG("No games to load");
    }
}

bool GameLibrary::removeGame(const std::string &gameId)
{
    auto it = findById(gameId);
    if (it != games.end())
    {
        games.erase(it);
        return true;
    }
    else
        return false;
}

std::vector<Game>::iterator GameLibrary::findById(const std::string &id)
{
    for (auto it = games.begin(); it != games.end(); it++)
    {
        if (it->getId() == id)
        {
            return it;
        }
    }
    return games.end();
}