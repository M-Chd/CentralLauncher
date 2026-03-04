#pragma once
#include "../domain/game.hpp"
#include "../domain/gameLibrary.hpp"
#include <iostream>
#include <vector>

namespace Services {

    class IGameRepository {
        public:
            virtual std::vector<Domain::Game> load() = 0;
            virtual void save(const Domain::GameLibrary&) = 0;
            virtual ~IGameRepository() = default;
    };
}