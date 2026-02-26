#include "jsonLoader.hpp"

using namespace std;
using namespace rapidjson;
typedef char byte;

vector<Game> JsonLoader::getGamesFromJson(const string& filepath)
{
	ifstream file(filepath);

	if (!file)
		throw;

	string json((istreambuf_iterator<char>(file), istreambuf_iterator<char>());

	Document d;
	d.Parse(json.c_str());

	if (d.HasParseError())
		throw;

	vector<Game> games;

	if (d.HasMember("games") && d["games"].IsArray()) {

		const auto& gameArray = d["games"];

		for (SizeType i = 0; i < gameArray.Size(); i++) {

			if (!gameArray[i].IsObject())
				throw;

			const auto& gameJson = gameArray[i];

			if (gameJson.HasMember("id") && gameJson.HasMember("name")
				&& gameJson.HasMember("path") && gameJson.HasMember("cat")) {

				Game game = Game(gameJson["id"].GetString(), gameJson["name"].GetString(),
				gameJson["path"].GetString(), gameJson["cat"].GetString());

				games.push_back(game);
			}
		}
	}
	return games;
}