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