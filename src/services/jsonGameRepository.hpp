#pragma once
#include "../domain/game.hpp"
#include "../util/debug.h"
#include "../domain/gameLibrary.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/rapidjson/writer.h"
#include "IGamesRepository.hpp"
#include <iostream>
#include <fstream>
#include <vector>

namespace Services
{

	class JsonGameRepository : public IGameRepository
	{

	public:
		JsonGameRepository(const std::string &filepath) : m_filepath(filepath) {};

		void save(const GameLibrary &) override;
		std::vector<Domain::Game> load() override;

	private:
		std::string m_filepath;
	};
}
