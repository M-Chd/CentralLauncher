#include "gameLauncherService.hpp"

#ifdef _WIN32

#include <Windows.h>
#include <shellapi.h>

#elif __linux__

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#elif __APPLE__

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#endif


using namespace Services;

void GameLaunchService::launch(const std::vector<Domain::Game>& games,const std::string& gameId)
{
    for (auto& g : games)
    {
        if (g.getId() == gameId)
        {
            std::string path = g.getGamePath();

        #ifdef _WIN32

            HINSTANCE result = ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOWNORMAL);

            if ((INT_PTR)result <= 32)
            {
                throw std::runtime_error("Process cannot be created");
            }

        #elif __linux__

            //TODO Linux

        #elif __APPLE__

            //TODO APPLE

        #endif

        }
    }
}