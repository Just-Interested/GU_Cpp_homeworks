#include <iostream>
#include <limits>
#include "Card.h"
#include "Player.h"
#include "House.h"
#include "Deck.h"
#include "Game.h"

bool Again(){
    std::cout << "Do you want to play again? (yY/nN): ";
    char ch;
    while(true){
        std::cin >> ch;
        if (std::cin && (((ch | 0x20) == 'y') || ((ch | 0x20) == 'n')))
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nIncorrect input! One more card? (yY/nN): ";
    }
    return ((ch | 0x20) == 'y');
}

std::vector<std::string> GetPlayersNames(){
    std::vector<std::string> players;
    std::cout << "Enter number of players: ";
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n')){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input! " << std::endl << "Enter number of players: ";
    }
    std::string tmp;
    for (int i = 1; i <= a; i++){
        std::cout << "Player " << i << " name: ";
        std::cin >> tmp;
        std::cout << std::endl;
        players.push_back(tmp);
    }
    return players;
}


int main(int argc, char* argv[]){
    std::vector<std::string> players;
    std::cout << "\n******** BlackJack New Game ********" << std::endl;
    players = GetPlayersNames();
    std::shared_ptr<Game> game = std::make_shared<Game>(players);
    do {
        game->Play();
    } while(Again());
    players.clear();
    return 0;
}