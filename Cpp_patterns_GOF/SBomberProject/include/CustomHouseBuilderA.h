#pragma once

#include "CustomHouseBuilder.h"

class CustomHouseBuilderA : public CustomHouseBuilder {
    void createHouse() override;
    void buildRoof() override;
    void buildDoor() override;
    void buildSkeleton() override;
    void buildWindow() override;
};