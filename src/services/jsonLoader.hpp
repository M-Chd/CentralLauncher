#pragma once
#include "src/domain/game.hpp"
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"
#include <iostream>
#include <vector>

class JsonLoader {

public:
	JsonLoader() {};
	~JsonLoader() {};

	std::vector<Game> getGamesFromJson(const std::string& filePath);
};
