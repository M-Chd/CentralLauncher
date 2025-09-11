#pragma once
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
#include <optional>
#include "Game.h"

class GameManager {

    std::vector<Game> games;

public:

    GameManager();
    ~GameManager() = default;

    std::vector<Game> getGames() const;

    void scanFolder();
    void addGame(Game g);
    void removeGame();
    void getFiltredGameList(); //??
    int searchGameIdx();
};