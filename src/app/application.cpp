#include "app/application.hpp"

using namespace App;

Application::Application()
{
    m_gameLaunchService = GameLaunchService();
    m_repository = JsonGameRepository("config/games.json");
    m_gameLibrary = GameLibrary();

    auto games = m_repository.load();
    m_gameLibrary.loadGames(games);

    
}