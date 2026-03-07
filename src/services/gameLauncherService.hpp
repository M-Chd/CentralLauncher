#pragma once
#include <iostream>
#include "domain/game.hpp"

namespace Services
{

    class GameLaunchService
    {
    public:
        void launch(Domain::Game &game);
    };
}