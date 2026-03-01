#include <iostream>
#include "src/domain/game.hpp"

namespace Services {
    
    class GameLaunchService
    {
    public:
        GameLaunchService(){};
        ~GameLaunchService(){};

        void launch(Domain::Game& game);

    };
}