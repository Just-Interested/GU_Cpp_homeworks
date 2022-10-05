
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include "Visitor.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void Bomb::Accept(Visitor& v) {
    v.log(*this);
}


void Bomb::AddObserver(Observer* o) {
    observers.push_back(o);
};

void Bomb::RemoveObserver(Observer* o) {
    for (auto iter = observers.begin(); iter != observers.end(); ++iter){
        if (*iter == o){
            observers.erase(iter);
            break;
        }
    }
};

DestroyableGroundObject* Bomb::CheckDestroyableGroundObjects() {
    for (auto o : observers){
        if (o->HandleInsideCheck(this->GetX(), this->GetY()))
            return dynamic_cast<DestroyableGroundObject*>(o);
    }
    return nullptr;
};