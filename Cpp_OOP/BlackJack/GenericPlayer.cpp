#include <iostream>
#include "GenericPlayer.h"


bool GenericPlayer::isBoosted() const{
    return (GetValue() > 21) ? true : false;
}

void GenericPlayer::Bust() const{
    std::cout << "Player " << name << "is boosted!" << std::endl;
}