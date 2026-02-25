#pragma once
#include "category.hpp"
#include <iostream>

class Game {
public:
	Game() {};
	~Game() {};

	std::string getName() { return name; }
	std::string getGamePath() { return path; }
	Category getCategory() const { return cat; }

	void launch();


private:

	std::string name;
	std::string path;
	Category cat;
	
};