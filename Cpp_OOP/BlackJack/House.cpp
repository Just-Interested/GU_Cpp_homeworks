#include "House.h"
#include <iostream>

bool House::isHitting() const{
    return (GetValue() <= 16);
}

void House::FlipFirstCard(){
    if (!m_cards.empty())
        m_cards[0]->flip();
    else
        std::cout << "Hand is empty!";
}