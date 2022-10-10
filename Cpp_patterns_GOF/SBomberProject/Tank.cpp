
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		pMediator->Notify(this, "Baaadaa Boom!");
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		pMediator->Notify(this, "Nooooo...");
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		pMediator->Notify(this, "That's hurt!");
		return true;
	}
	pMediator->Notify(this, "Looser!");
	return false;
}

void Tank::Draw() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";
}