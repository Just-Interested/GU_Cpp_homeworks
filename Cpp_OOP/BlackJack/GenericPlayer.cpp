#include <iostream>
#include <vector>
#include <iomanip>
#include "GenericPlayer.h"


bool GenericPlayer::isBoosted() const{
    return (GetValue() > 21) ? true : false;
}

void GenericPlayer::Bust() const{
    std::cout << name << " is boosted!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& rGenericPlayer)
{
    std::string tmp = rGenericPlayer.name + ":";
    os << std::left << std::setw(10) << tmp;
    if (!rGenericPlayer.m_cards.empty()) {
        for (Card* pCard : rGenericPlayer.m_cards){
            os << (*pCard) << "    ";
        }
        os << std::endl;
    }
    else
        os << "<empty>" << std::endl;
    return os;
}