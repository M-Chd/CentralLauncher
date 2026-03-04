#pragma once
#include <iostream>
#include "../services/gameLauncherService.hpp"
#include "../domain/gameLibrary.hpp"
#include "../services/jsonGameRepository.hpp"
#include "../services/IGamesRepository.hpp"
#include "util/debug.h"


namespace App
{
    class Application
    {
    public:

        Application();

        bool initWindow();
        void quit();
        void run();

    private:

        GameLibrary m_gameLibrary;
        GameLaunchService m_gameLaunchService;
        std::unique_ptr<IGameRepository> m_repository;

    };

}