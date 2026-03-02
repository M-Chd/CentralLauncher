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

		void addGame(Game &g) { games.push_back(g); }

		bool removeGame(const std::string& gameId);

		std::vector<Game> &getGames() { return games; }

	private:
		std::vector<Game> games;

		std::vector<Game>::iterator findById(const std::string& id);
	};
}