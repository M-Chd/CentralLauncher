#pragma once
#include <iostream>
#include <memory>
#include "services/gameLauncherService.hpp"
#include "domain/gameLibrary.hpp"
#include "services/jsonGameRepository.hpp"

class Domain::GameLibrary;
class Services::GameLaunchService;
class Services::IGameRepository;

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

        Domain::GameLibrary m_gameLibrary;
        Services::GameLaunchService m_gameLaunchService;
        std::unique_ptr<Services::IGameRepository> m_repository;

    };

}