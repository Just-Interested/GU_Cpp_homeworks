#include <iostream>
#include <limits>
#include "Card.h"
#include "Player.h"
#include "House.h"


int main(int argc, char* argv[]){

    Player* pPlayer = new Player("Jhon");
    pPlayer->Add(new Card(Card::TEN, Card::SPADES));
    pPlayer->Add(new Card(Card::ACE, Card::CLUBS));
    std::cout << *pPlayer << std::endl;
    pPlayer->Open();
    std::cout << *pPlayer << std::endl;
    delete pPlayer;
    
    House* pHouse = new House;
    pHouse->Add(new Card(Card::KING, Card::CLUBS));
    pHouse->Add(new Card(Card::ACE, Card::SPADES));
    pHouse->FlipFirstCard();
    std::cout << *pHouse << std::endl;
    delete pHouse;
    
    return 0;
}