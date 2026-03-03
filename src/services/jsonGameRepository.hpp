#pragma once
#include "src/domain/game.hpp"
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"
#include "src/domain/gameLibrary.hpp"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include <iostream>
#include <fstream>
#include <vector>

namespace Services
{

	class JsonGameRepository
	{

	public:
		
		explicit JsonGameRepository(const std::string& filepath);

		void save(const GameLibrary&);
		std::vector<Domain::Game> load();

	private:
		std::string m_filepath;

	};
}
