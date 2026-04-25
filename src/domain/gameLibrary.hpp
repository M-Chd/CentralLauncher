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

		GameLibrary();

		void loadGames(const std::vector<Game>& l_games);
	
		void addGame(Game &g) { games.emplace_back(g); }

		bool removeGame(const std::string &gameId);

		const std::vector<Game> &getGames() const { return games; }

		std::pair<Domain::Game,bool> searchGame(const std::string& id);

		std::vector<Game> searchGamebyName(const std::string& name);

	protected:
		std::vector<Game>::iterator findById(const std::string &id);

	private:
		std::vector<Game> games;
	};
}