#include "gameLibrary.hpp"

using namespace Domain;

GameLibrary::GameLibrary()
{
    games.reserve(15);
}

void GameLibrary::loadGames(const std::vector<Game>& l_games)
{
    if (!l_games.empty())
    {
        for (auto &g : l_games)
        {
            games.emplace_back(g);
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

std::pair<Domain::Game,bool> Domain::GameLibrary::searchGame(const std::string& id)
{
    if (!games.empty()) {
        for (auto& g : games)
        {
            if (g.getId() == id)
            {
                return { g, true };
            }
        }
    }
    LOG("No game with this Id found");
    std::cout << "No game with the following id: " << id << " exist..." << "\n";
    return { Domain::Game(),false };
}

std::vector<Game> Domain::GameLibrary::searchGamebyName(const std::string& name)
{
    std::vector<Game> foundGames;
    foundGames.reserve(15);

    if (!games.empty()) {
        for (auto& g : games)
        {
            if (g.getName() == name)
            {
                foundGames.emplace_back(g);
            }
        }
    }
    return foundGames;
}