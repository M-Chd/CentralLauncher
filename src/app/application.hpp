#pragma once
#include <iostream>
#include <memory>
#include <chrono>
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

        std::vector<Domain::Game> getLibrary();
        void addGame(const std::string filePath, const std::string gameName,
            const std::string category);
        void removeGame(const std::string gameID);
        Domain::Game getGameById(const std::string& gameId);
        void launchgame(const std::string& gameId);

    private:
        void init();
        std::string generateID();

    private:

        Domain::GameLibrary m_gameLibrary;
        Services::GameLaunchService m_gameLaunchService;
        std::unique_ptr<Services::IGameRepository> m_repository;

    };

}