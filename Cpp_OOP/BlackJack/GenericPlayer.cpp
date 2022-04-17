#include <iostream>
#include <vector>
#include "GenericPlayer.h"


bool GenericPlayer::isBoosted() const{
    return (GetValue() > 21) ? true : false;
}

void GenericPlayer::Bust() const{
    std::cout << "Player " << name << "is boosted!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& rGenericPlayer)
{
    os << rGenericPlayer.name << ": ";
    if (!rGenericPlayer.m_cards.empty()) {
        for (Card* pCard : rGenericPlayer.m_cards){
            os << (*pCard) << "\t";
        }
        os << std::endl;
    }
    else
        os << "<empty>" << std::endl;
    return os;
}