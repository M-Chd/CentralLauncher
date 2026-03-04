#pragma once

#include <iostream>

#ifdef DEBUG

    #define LOG(x) \ std::cout << "[DEBUG] " << __FILE__ \ << ":" << __LINE__ \ << " -> " << x << std::endl;

#else

    #define LOG(x)

#endif