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

void GameLibrary::deleteGame(const std::string& gameId)
{
    if (!games.empty())
    {
        for (size_t i = 0; i < games.size() ; i++ )
        {
            if (games[i].getId() == gameId)
            {
                games.erase(games.begin() + i);
            }
        }
    }
    std::cerr << "No games correspond with the given Id... " << "\n";
}