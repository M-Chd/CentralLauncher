#include <iostream>
#include "app/application.hpp"

int main() {
	
	try {
		App::Application app;
	}
	catch (std::runtime_error e) {
		printf(e.what());
	}

	return 0;
}