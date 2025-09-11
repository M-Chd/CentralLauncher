#include "GameManager.h"

GameManager::GameManager() {};

std::vector<Game> GameManager::getGames() const
{
    return games;
}

void GameManager::addGame(Game g)
{
    games.push_back(g);
}

int GameManager::searchGameIdx()
{

    std::string search;
    std::cin>>search;

    std::transform(search.begin(),search.end(),search.begin(), ::toupper);

    for (int i = 0; i < games.size(); i++){

        auto name = games[i].getName();
        std::transform(name.begin(),name.end(),name.begin(), ::toupper);

        if (name == search){
            return i;
        }
    }
    return -1;
}

void GameManager::removeGame()
{

    auto searchIdx = searchGameIdx();

    if (searchIdx != -1 && searchIdx < games.size()){
        games.erase(games.begin() + searchIdx);
    }
    
}
