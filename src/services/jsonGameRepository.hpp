#pragma once
#include "src/domain/game.hpp"
#include "include/rapidjson/document.h"
#include "include/rapidjson/filereadstream.h"
#include "src/domain/gameLibrary.hpp"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include "src/services/IGamesRepository.hpp"
#include <iostream>
#include <fstream>
#include <vector>

namespace Services
{

	class JsonGameRepository : public IGameRepository
	{

	public:
		
		JsonGameRepository(const std::string& filepath);

		void save(const GameLibrary&) override;
		std::vector<Domain::Game> load() override;

	private:
		std::string m_filepath;

	};
}
