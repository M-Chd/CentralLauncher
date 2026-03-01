#pragma once
#include <iostream>
#include "src/services/gameLauncherService.hpp"
#include "src/domain/gameLibrary.hpp"

using namespace Domain;
using namespace Services;


namespace App
{
    class Application
    {
    public:

        void init();
        bool initWindow();
        void quit();

    private:

        GameLibrary m_gameLibrary;
        GameLaunchService m_gameLaunchService;

    };

}