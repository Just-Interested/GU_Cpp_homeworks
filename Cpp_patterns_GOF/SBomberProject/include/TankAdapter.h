#pragma once

#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter : public DestroyableGroundObject {
private:
    TankAdaptee* tank;
public:
    TankAdapter() : tank(new TankAdaptee) {};
    void SetPos(double nx, double ny) override { tank->SetPos(nx, ny); }
    double GetY() const override { return tank->GetY(); }
    double GetX() const override { return tank->GetX(); }
    uint16_t GetWidth() const override { return tank->GetWidth(); }
    void Draw() const override { tank->Paint(); }
    uint16_t GetScore() const override { return tank->GetScore(); }
    bool isInside(double nx, double ny) const override { return tank->isInRange(nx, ny); } 
};