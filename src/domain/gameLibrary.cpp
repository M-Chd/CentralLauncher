#include "gameLibrary.hpp"

using namespace Domain;

/**
 * Load from JsonLoader
 */
void GameLibrary::load(std::vector<Game>& v_games)
{
    for (auto& g : v_games){
        games.push_back(g);
    }
}

bool GameLibrary::removeGame(const std::string& gameId)
{
    auto it = findById(gameId);
    if (it != games.end()){
        games.erase(it);
        return true;
    } else
        return false;
}

std::vector<Game>::iterator GameLibrary::findById(const std::string& id)
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