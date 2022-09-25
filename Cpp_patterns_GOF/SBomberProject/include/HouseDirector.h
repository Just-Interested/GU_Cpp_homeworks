#pragma once

#include "CustomHouseBuilder.h"

class HouseDirector {
public:
    CustomHouse* createCustomHouse(CustomHouseBuilder* builder) {
        builder->createHouse();
        builder->buildSkeleton();
        builder->buildDoor();
        builder->buildWindow();
        builder->buildRoof();
        return builder->GetHouse();
    }
};