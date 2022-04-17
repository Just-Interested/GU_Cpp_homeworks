#ifndef HOUSE_H
#define HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer{
public:
    House() : GenericPlayer("House"){}
    ~House(){};
    bool isHitting() const;
    void FlipFirstCard();
};

#endif