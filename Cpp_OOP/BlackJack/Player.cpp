#include "Player.h"
#include "Card.h"
#include <iostream>
#include <limits>

bool Player::isHitting() const{
    if (GetValue() >= 21)
        return false;
    std::cout << "Do you need one more card? (yY/nN): ";
    char ch;
    while(true){
        std::cin >> ch;
        if (std::cin && (((ch | 0x20) == 'y') || ((ch | 0x20) == 'n')) && std::cin.peek() == '\n')
            break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nIncorrect input! One more card? (yY/nN): ";
    }
    return ((ch | 0x20) == 'y');
}

void Player::Lose() const{
    std::cout << name << " lose!" << std::endl;
}

void Player::Win() const{
    std::cout << name << " win!" << std::endl;
}

void Player::Push() const{
    std::cout << name << " played for a draw!" << std::endl;
}

void Player::Open(){
    for (Card* pCard : m_cards)
        pCard->flip();
}