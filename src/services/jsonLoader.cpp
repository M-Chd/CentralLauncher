#include "jsonLoader.hpp"

using namespace rapidjson;
using namespace Domain;

std::vector<Game> Services::JsonLoader::loadGamesFromJson(const string& filepath)
{
	std::ifstream jsonFile(filepath);

	if (!jsonFile) {
		std::cerr << "Json file was not found" << "\n";
		throw std::runtime_error("Json file not found");
	}

	std::string json{std::istreambuf_iterator<char>(jsonFile), std::istreambuf_iterator<char>()};

	Document d;
	d.Parse(json.c_str());

	if (d.HasParseError()){
		std::cerr << "Error during parsing..." << "\n";
		throw std::runtime_error("Error during parsing");
	}

	std::vector<Game> games;

	if (d.HasMember("games") && d["games"].IsArray()) {

		const auto& gameArray = d["games"];

		for (SizeType i = 0; i < gameArray.Size(); i++) {

			if (!gameArray[i].IsObject())
				throw std::runtime_error("No object in JsonFile");

			const auto& gameJson = gameArray[i];

			if (gameJson.HasMember("id") && gameJson.HasMember("name")
				&& gameJson.HasMember("executable") && gameJson.HasMember("cat")) {

				Game game = Game(gameJson["id"].GetString(), gameJson["name"].GetString(),
				gameJson["executable"].GetString(), gameJson["cat"].GetString());

				games.push_back(game);
			}
		}
	}
	return games;
}