#pragma once
#include <iostream>
#include <vector>
#include "domain/game.hpp"
#include "util/debug.h"

namespace Domain
{
	class GameLibrary
	{
	public:

		void loadGames(const std::vector<Game>& l_games);
	
		void addGame(Game &g) { games.emplace_back(g); }

		bool removeGame(const std::string &gameId);

		const std::vector<Game> &getGames() const { return games; }

		void displayGamesOnConsole();

	private:
		std::vector<Game> games;

	protected:
		std::vector<Game>::iterator findById(const std::string &id);
	};
}