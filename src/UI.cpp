#include "UI.h"

void showGameList(GameManager gM){

    auto games = gM.getGames();

    if (games.empty()){
        std::cout<<"The game list is empty"<<"\n";
    }

    std::cout << "|====Game List====|" << "\n";

    for (Game g : gM.getGames()){
        std::cout<<"Game name : " + g.getName() + " | Platform : " + g.getPlatform() <<"\n";
    }
    std::cout<<"================="<<"\n";
}

void showGameDetails(Game g){

    std::cout<<"Name : " + g.getName()<<"\n";
    std::cout<<"Platform : " + g.getPlatform()<<"\n";
    std::cout<<"Path : " + g.getPath()<<"\n";
    std::cout<<"Last time played : " + g.getLastPlayed()<<"\n";
}

void searchGames(GameManager gm){

    std::string search;
    std::cin>>search;
    std::transform(search.begin(),search.end(),search.begin(), ::toupper);

    auto games = gm.getGames();

    for (auto& g : games){
        
        auto name = g.getName();
        std::transform(name.begin(),name.end(),name.begin(), ::toupper);

        if (name == search){
            std::cout<<g.getName()<<"\n";
        }
    }
}