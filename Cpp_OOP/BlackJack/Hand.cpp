#include "Hand.h"


Hand::~Hand(){
    Clear();
    //std::cout << "~Hand()" << std::endl;
}

void Hand::Add(Card* pCard){
    m_cards.push_back(pCard);
}

void Hand::Clear(){
    for (Card* pCard : m_cards)
        delete pCard;
    m_cards.clear();
}

int Hand::GetValue() const{
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