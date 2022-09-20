#pragma once

#include "Bomb.h"

class BombDecorator : public AbstractBomb {
private:
    Bomb* bomb;
public:
    BombDecorator(){
        bomb = new Bomb;
    };
    void Draw() const override;
    void Move(uint16_t time) override;
    void SetPos(double nx, double ny) { bomb->SetPos(nx, ny); }
    double GetY() const { return bomb->GetY(); }
    double GetX() const { return bomb->GetX(); }
    void SetWidth(uint16_t widthN) { bomb->SetWidth(widthN); }
    uint16_t GetWidth() const { return bomb->GetWidth(); }
    void SetSpeed(double sp) { bomb->SetSpeed(sp); }
    void SetDirection(double dx, double dy) { bomb->SetDirection(dx, dy); }
};