#pragma once
#include <iostream>

using std::string;

class Game {
public:
	Game(string _id, string _name, string _path, string _cat) : 
		id(_id), name(_name),path(_path),cat(_cat)
	{
		if (!_id || !_name || !_path || !_cat)
			return;
	};

	~Game() {};

	string getId() const { return id; }
	string getName() const { return name; }
	string getGamePath() const { return path; }
	string getCategory() const { return cat; }

	void launch();

private:
	string id;
	string name;
	string path;
	string cat;
};