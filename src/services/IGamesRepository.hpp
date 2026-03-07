#pragma once
#include "domain/game.hpp"
#include "domain/gameLibrary.hpp"
#include <iostream>
#include <vector>

namespace Services {

    class IGameRepository {
        public:
            virtual void saveRepo(const Domain::GameLibrary& library) = 0;
            virtual std::vector<Domain::Game> loadRepo() = 0;
            virtual ~IGameRepository() = default;
    };
}