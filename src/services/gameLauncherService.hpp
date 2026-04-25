#pragma once
#include <iostream>
#include <vector>
#include "domain/game.hpp"

namespace Services
{

    class GameLaunchService
    {
    public:
        void launch(const std::vector<Domain::Game>& games, const std::string& gameId);
    };
}