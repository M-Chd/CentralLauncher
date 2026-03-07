#include "application.hpp"

using namespace App;
using namespace Domain;
using namespace Services;

Application::Application()
    : m_gameLibrary(),
    m_gameLaunchService(),
    m_repository(std::make_unique<Services::JsonGameRepository>("config/game.json"))
{
}

void App::Application::init()
{
    try {
        m_gameLibrary.loadGames(m_repository->loadRepo());
    }
    catch (std::runtime_error e) {
        printf(e.what());
    }
}

void App::Application::run()
{
    init();
    Game g = Game("testId", "Test", "...", "testCat");
    m_gameLibrary.addGame(g);
    m_gameLibrary.displayGamesOnConsole();
}