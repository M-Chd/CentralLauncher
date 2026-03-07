#include "jsonGameRepository.hpp"

using namespace rapidjson;
using namespace Domain;

std::vector<Game> Services::JsonGameRepository::loadRepo()
{
	//std::cout << "Current Dir : " << std::filesystem::current_path() << std::endl;

	std::ifstream jsonFile(m_filepath);

	if (!jsonFile)
	{
		ERROR("Json file not found");
		throw std::runtime_error("Json file not found");
	}

	std::string json{std::istreambuf_iterator<char>(jsonFile), std::istreambuf_iterator<char>()};

	Document d;
	d.Parse(json.c_str());

	if (d.HasParseError())
	{
		ERROR("error during parsing");
		throw std::runtime_error("Error during parsing");
	}

	std::vector<Game> games;

	if (d.HasMember("games") && d["games"].IsArray())
	{

		const auto &gameArray = d["games"];

		for (SizeType i = 0; i < gameArray.Size(); i++)
		{

			if (gameArray[i].IsObject())
			{
				const auto &gameJson = gameArray[i];

				if (gameJson.HasMember("id") && gameJson.HasMember("name") &&
					gameJson.HasMember("executable") && gameJson.HasMember("category"))
				{

					Game game = Game(gameJson["id"].GetString(), gameJson["name"].GetString(),
									 gameJson["executable"].GetString(), gameJson["category"].GetString());

					games.emplace_back(game);
				}
				else
				{
					ERROR("No games found");
					LOG(gameJson);
				}
			}
			else
			{
				ERROR("No Object found in the JsonFile...");
				LOG(gameArray);
			}
		}
	}
	#ifdef DEBUG
		for (const auto& g : games)
		{
			print(g.getName());
		}
	#endif
	return games;
}

void Services::JsonGameRepository::saveRepo(const Domain::GameLibrary &library)
{
	Document d;
	d.SetObject();
	auto &allocator = d.GetAllocator();

	Value gamesArray(kArrayType);

	for (const auto &game : library.getGames())
	{
		Value gameObject(kObjectType);

		gameObject.AddMember("id",
							 Value(game.getId().c_str(), allocator),
							 allocator);

		gameObject.AddMember("name",
							 Value(game.getName().c_str(), allocator),
							 allocator);

		gameObject.AddMember("executable",
							 Value(game.getGamePath().c_str(), allocator),
							 allocator);
		
		gameObject.AddMember("category",Value(game.getCategory().c_str(), allocator),
							 allocator);

		gamesArray.PushBack(gameObject, allocator);
	}

	d.AddMember("games", gamesArray, allocator);

	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	d.Accept(writer);

	std::ofstream out(m_filepath);
	if (!out)
		throw std::runtime_error("Failed to open file for writing");

	out << buffer.GetString();
}