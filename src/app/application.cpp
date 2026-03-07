#include "application.hpp"

using namespace App;
using namespace Domain;
using namespace Services;

Application::Application()
    : m_gameLibrary(),
    m_gameLaunchService(),
    m_repository(std::make_unique<Services::JsonGameRepository>("config/games.json"))
{
    m_gameLibrary.loadGames(m_repository->loadRepo());
}