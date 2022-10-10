#include <iostream>

#include "BigPlane.h"
#include "MyTools.h"

void BigPlane::DrawBody() const {
    MyTools::SetColor(MyTools::CC_LightBlue);
    MyTools::GotoXY(x, y);
    std::cout << "==========>";
}

void BigPlane::DrawTail() const {
    MyTools::SetColor(MyTools::CC_LightBlue);
    MyTools::GotoXY(x - 2, y - 1);
    std::cout << "====";
}

void BigPlane::DrawWings() const {
    MyTools::SetColor(MyTools::CC_LightBlue);
    MyTools::GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\\\";
    MyTools::GotoXY(x + 3, y + 1);
    std::cout << "/////";
}