#pragma once

#include <iostream>

#ifdef DEBUG

#define LOG(x) \ std::cout << "[DEBUG] " << __FILE__ \ << ":" << __LINE__ \ << " -> " << x << std::endl;
#define ERROR(x) \ std::cout << "[ERROR] in file: " << __FILE__ \ << " line:" << __LINE__ \ << " -> " << x << std::endl;
#define WARNING(x) \ std::cout << "[WARNING] in file: " << __FILE__ \ << " line:" << __LINE__ \ << " -> " << x << std::endl;

#else

#define LOG(x)
#define ERROR(x)
#define WARNING(x)

#endif