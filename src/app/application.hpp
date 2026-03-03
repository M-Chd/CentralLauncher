#pragma once
#include <iostream>
#include "src/services/gameLauncherService.hpp"
#include "src/domain/gameLibrary.hpp"
#include "src/services/jsonGameRepository.hpp"

using namespace Domain;
using namespace Services;


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
        JsonGameRepository m_repository;

    };

}