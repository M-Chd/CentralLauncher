#pragma once
#include "domain/game.hpp"
#include "util/debug.h"
#include "domain/gameLibrary.hpp"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "IGamesRepository.hpp"
#include <fstream>
#include <vector>


namespace Services
{

	class JsonGameRepository : public IGameRepository
	{

	public:
		JsonGameRepository(const std::string &filepath) : m_filepath(filepath) {};

		void saveRepo(const Domain::GameLibrary &library) override;
		std::vector<Domain::Game> loadRepo() override;

	private:
		std::string m_filepath;
	};
}
