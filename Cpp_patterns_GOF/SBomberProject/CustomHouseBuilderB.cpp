#include "CustomHouseBuilderB.h"

void CustomHouseBuilderB::createHouse() {
    house = new CustomHouse;
    house->color = MyTools::CC_Cyan;
    house->score = 20;
};

void CustomHouseBuilderB::buildDoor() {
    for (size_t i = C_HOUSE_WIDTH - 5; i < C_HOUSE_WIDTH - 2; i++)
    {
        for (size_t j = C_HOUSE_HEIGHT - 4; j < C_HOUSE_HEIGHT - 1; j++)
        {
            house->look[j][i] = '#';
        }
    }
};

void CustomHouseBuilderB::buildSkeleton() {
    for (size_t i = 2; i < C_HOUSE_HEIGHT; i++)
    {
        house->look[i][0] = '#';
        house->look[i][C_HOUSE_WIDTH - 1] = '#';
    }
    for (size_t i = 0; i < C_HOUSE_WIDTH; i++)
    {
        house->look[C_HOUSE_HEIGHT-1][i] = '#';
        house->look[2][i] = '#';
    }
     
};

void CustomHouseBuilderB::buildWindow() {
    house->look[C_HOUSE_HEIGHT-4][2] = '#';
    house->look[C_HOUSE_HEIGHT-4][3] = '#';
    house->look[C_HOUSE_HEIGHT-3][2] = '#';
    house->look[C_HOUSE_HEIGHT-3][3] = '#';
};