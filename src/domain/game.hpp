#pragma once
#include <iostream>

using std::string;

namespace Domain
{
	class Game
	{
	public:
		Game(string _id, string _name, string _path, string _cat) : id(_id), name(_name), path(_path), cat(_cat)
		{
			if (_id == "" || _name == "" || _path == "" || _cat == "")
				throw std::invalid_argument("Game cannot be created...");
		};
		Game() {};

		string getId() const { return id; }
		string getName() const { return name; }
		string getGamePath() const { return path; }
		string getCategory() const { return cat; }

	private:
		string id;
		string name;
		string path;
		string cat;
	};
}