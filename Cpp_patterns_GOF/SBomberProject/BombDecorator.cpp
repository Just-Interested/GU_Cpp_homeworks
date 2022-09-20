#include "BombDecorator.h"
#include "MyTools.h"

#include <iostream>

void BombDecorator::Move(uint16_t time)
{
    bomb->Move(time * 1.6);
}


void BombDecorator::Draw() const
{
    bomb->Draw();
    // Некоторое изменение внешнего вида бомбы
    MyTools::GotoXY(bomb->GetX(), bomb->GetY() - 1);
    std::cout << "|";
}