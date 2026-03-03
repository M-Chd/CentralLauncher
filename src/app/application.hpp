#pragma once
#include <iostream>
#include "src/services/gameLauncherService.hpp"
#include "src/domain/gameLibrary.hpp"
#include "src/services/jsonGameRepository.hpp"
#include "src/services/IGamesRepository.hpp"


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