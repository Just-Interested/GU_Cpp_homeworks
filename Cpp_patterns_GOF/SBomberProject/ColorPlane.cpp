#include <iostream>

#include "ColorPlane.h"
#include "MyTools.h"

void ColorPlane::DrawBody() const {
    MyTools::SetColor(MyTools::CC_Green);
    MyTools::GotoXY(x, y);
    std::cout << "=========>";
}

void ColorPlane::DrawTail() const {
    MyTools::SetColor(MyTools::CC_Blue);
    MyTools::GotoXY(x - 2, y - 1);
    std::cout << "===";
}

void ColorPlane::DrawWings() const {
    MyTools::SetColor(MyTools::CC_Cyan);
    MyTools::GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    MyTools::GotoXY(x + 3, y + 1);
    std::cout << "////";
}