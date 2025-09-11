#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <optional>
#include "game.h"
#include "GameManager.h"

void showGameList(GameManager gM);
void showGameDetails(Game g);
void promptLauncherGame();
void searchGames(std::string name);