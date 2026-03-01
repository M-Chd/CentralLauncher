#pragma once
#include "src/domain/game.hpp"
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"
#include <iostream>
#include <fstream>
#include <vector>

namespace Services
{

	class JsonLoader
	{

	public:
		JsonLoader() {};
		~JsonLoader() {};

		std::vector<Domain::Game> loadGamesFromJson(const std::string &filePath);
	};
}
