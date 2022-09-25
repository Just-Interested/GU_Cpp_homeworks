#pragma once

#include "CustomHouse.h"

class CustomHouseBuilder {
protected:
    CustomHouse* house;
public:
    CustomHouseBuilder() : house(0) {};
    virtual ~CustomHouseBuilder() {};
    virtual void createHouse(){};
    virtual void buildRoof(){};
    virtual void buildDoor(){};
    virtual void buildSkeleton(){};
    virtual void buildWindow(){};
    CustomHouse* GetHouse() const { return house; };
};