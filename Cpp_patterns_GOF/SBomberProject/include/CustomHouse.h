#pragma once 

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include "MyTools.h"

#define C_HOUSE_WIDTH 14
#define C_HOUSE_HEIGHT 7

class CustomHouse : public DestroyableGroundObject {
private:
    char look[C_HOUSE_HEIGHT][C_HOUSE_WIDTH];
    uint16_t score = 40;
    MyTools::ConsoleColor color = MyTools::CC_Yellow;
    friend class CustomHouseBuilderA;
    friend class CustomHouseBuilderB;
public:
    CustomHouse(){
        for (size_t i = 0; i < C_HOUSE_HEIGHT; i++)
        {
            for (size_t j = 0; j < C_HOUSE_WIDTH; j++)
            {
                look[i][j] = ' ';
            }        
        }
    }
    bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
};