#ifndef PLAYER_H
#define PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer{
public:
    Player(std::string name) : GenericPlayer(name){}
    ~Player(){};
    bool isHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
    void Open();
};


#endif