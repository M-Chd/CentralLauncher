#include "FileManager.h"

namespace fs = std::filesystem;

void listFilesInDirectory(std::string path){
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << "\n";
    }
}