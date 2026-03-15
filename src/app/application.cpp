#include "application.hpp"

using namespace App;
using namespace Domain;
using namespace Services;

using std::string;

Application::Application()
    : m_gameLibrary(),
    m_gameLaunchService(),
    m_repository(std::make_unique<Services::JsonGameRepository>("config/game.json"))
{
    init();
}

std::vector<Domain::Game> App::Application::getLibrary()
{
    return m_gameLibrary.getGames();
}

void App::Application::addGame(const string filePath,const string gameName,const string category)
{
    auto gameID = generateID();
    Game g = Game(gameID, gameName, filePath, category);
    m_gameLibrary.addGame(g);
    m_repository->saveRepo(m_gameLibrary);
}

string App::Application::generateID()
{
    // is good ?
    auto time = std::chrono::system_clock::now();
    auto duration = time.time_since_epoch();
    auto count = duration.count();
    return std::to_string(count);
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

/*
void App::Application::run()
{
    init();
    Game g = Game("testId", "Test", "...", "testCat");
    m_gameLibrary.addGame(g);
    m_gameLibrary.displayGamesOnConsole();
}
*/

