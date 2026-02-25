#pragma once
#include <iostream>
#include <vector>
#include "game.hpp"

class GameLibrary {
public:
	GameLibrary() {};
	~GameLibrary() {};

	void load();

	bool addGames(Game& g)
	{
		if (g != nullptr) {
			games.push_back(g);
			return true;
		}
		return false;
	}

	void deleteGame(std::string gameName);

	std::vector<Game>& getGames() { return games; }

private:

	std::vector<Game> games;
};