#include <iostream>
#include "BlackJack.h"


// *********** Card class ***********
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
	
void Card::show() const{
    std::cout << "**** CARD ****" << std::endl;
    std::cout << "Rank: ";
    switch(this->rank){
        case ACE : std::cout << "ACE" << std::endl;   break;
        case TWO : std::cout << "TWO" << std::endl;   break;
        case THREE : std::cout << "THREE" << std::endl;   break;
        case FOUR : std::cout << "FOUR" << std::endl;   break;
        case FIVE : std::cout << "FIVE" << std::endl;   break;
        case SIX : std::cout << "SIX" << std::endl;   break;
        case SEVEN : std::cout << "SEVEN" << std::endl;   break;
        case EIGHT : std::cout << "EIGHT" << std::endl;   break;
        case NINE : std::cout << "NINE" << std::endl;   break;
        case TEN : std::cout << "TEN" << std::endl;   break;
        case JACK : std::cout << "JACK" << std::endl;   break;
        case QUEEN : std::cout << "QUEEN" << std::endl;   break;
        case KING : std::cout << "KING" << std::endl;   break;
    }
    std::cout << "Suit: ";
    switch(this->suit){
        case SPADES : std::cout << "SPADES" << std::endl;   break;
        case HEARTS : std::cout << "HEARTS" << std::endl;   break;
        case DIAMONDS : std::cout << "DIAMONDS" << std::endl;   break;
        case CLUBS : std::cout << "CLUBS" << std::endl;   break;
    }
    std::cout << "Value: " << getValue() << std::endl; 
    std::cout << "**************" << std::endl;
}

// Task 3
// *********** Hand class ***********
Hand::Hand(){
    m_cards.clear();
}

Hand::~Hand(){
    Clear();
}

void Hand::Add(Card* pCard){
    m_cards.push_back(pCard);
}

void Hand::Clear(){
    for(Card* pCard : m_cards)
        delete pCard;
    m_cards.clear();
}

int Hand::GetValue(){
    if (m_cards.empty())
        return 0;
    int result = 0;
    int current_value;
    for (Card* pCard : m_cards){
        current_value = pCard->getValue();
        if (result <= 21 && current_value == 1)
            current_value = 11;
        result += current_value;
    }
    return result;
}
