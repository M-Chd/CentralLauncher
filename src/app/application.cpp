#include "app/application.hpp"

using namespace App;
using namespace Domain;
using namespace Services;

Application::Application()
    : m_gameLibrary(),
      m_gameLaunchService()
{

    this->m_repository = std::make_unique<JsonGameRepository>("config/games.json");

    auto games = m_repository->load();
    m_gameLibrary.loadGames(games);
}