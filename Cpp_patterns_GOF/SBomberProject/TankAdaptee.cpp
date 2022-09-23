#include <iostream>

#include "TankAdaptee.h"
#include "MyTools.h"

void TankAdaptee::Paint(){
    MyTools::SetColor(MyTools::CC_Green);
	MyTools::GotoXY(x, y - 3);
	std::cout << "    #####";
	MyTools::GotoXY(x-2, y - 2);
	std::cout << "#######   #";
	MyTools::GotoXY(x, y - 1);
	std::cout << "    #####";
	MyTools::GotoXY(x,y);
	std::cout << " ###########";
}

bool TankAdaptee::isInRange(double x1, double x2) const {
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
}