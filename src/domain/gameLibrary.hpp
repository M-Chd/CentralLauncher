#pragma once
#include <iostream>
#include <vector>
#include "game.hpp"

namespace Domain
{
	class GameLibrary
	{
	public:
		GameLibrary() {};
		~GameLibrary() {};

		void load(std::vector<Game>& v_games); // load the game with the json file

		void addGames(Game &g) { games.push_back(g); }

		void deleteGame(std::string gameId);

		std::vector<Game> &getGames() { return games; }

	private:
		std::vector<Game> games;
	};
}