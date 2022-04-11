#include <iostream>
#include "Card.h"

Card::Card(){
    this->rank = ACE;
    this->suit = SPADES;
    m_IsFaceUp = false;
}

Card::Card(Rank rank, Suit suit, bool m_IsFaceUp){
    this->rank = rank;
    this->suit = suit;
    this->m_IsFaceUp = m_IsFaceUp;
}

void Card::flip() {
    m_IsFaceUp = !m_IsFaceUp;
}

int Card::getValue() const{
    if (this->rank > 10)
        return 10;
    return rank;
}


std::ostream& operator<<(std::ostream& os, const Card& rCard){
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const char SUITS[] = { 6, 3, 4, 5}; // ascii for suit simbols
    if (rCard.m_IsFaceUp)
        os << RANKS[rCard.rank] << SUITS[rCard.suit];
    else 
        os << "XX";
    return os;
}