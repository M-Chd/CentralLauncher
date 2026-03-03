#include <iostream>
#include "src/domain/game.hpp"

namespace Services
{

    class GameLaunchService
    {
    public:
        void launch(Domain::Game &game);
    };
}