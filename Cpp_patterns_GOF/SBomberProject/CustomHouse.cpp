#include <iostream>

#include "CustomHouse.h"


bool CustomHouse::isInside(double x1, double x2) const {
    const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
};


void CustomHouse::Draw() const
{
	MyTools::SetColor(color);
    for (size_t i = 0; i < C_HOUSE_HEIGHT; i++)
    {
        MyTools::GotoXY(x, y - C_HOUSE_HEIGHT + 1 + i);
        for (size_t j = 0; j < C_HOUSE_WIDTH; j++)
        {
            std::cout << look[i][j];
        }        
    }
}