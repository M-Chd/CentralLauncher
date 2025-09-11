#include <iostream>
#include "FileManager.h"
#include "UI.h"

int main(){

    std::string Path = "C:/Windows";

    GameManager gameMang;
    
    Game* testGame = new Game("Test","Steam");

    listFilesInDirectory(Path);

    return 0;
}