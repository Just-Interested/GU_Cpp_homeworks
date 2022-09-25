#pragma once

#include "CustomHouseBuilder.h"

class CustomHouseBuilderB : public CustomHouseBuilder {
    void createHouse() override;
    void buildDoor() override;
    void buildSkeleton() override;
    void buildWindow() override;
};