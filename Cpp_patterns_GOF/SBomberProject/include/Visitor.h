#pragma once

#include "Plane.h"
#include "Bomb.h"

class Visitor {
public:
    virtual void log(Plane&) = 0;
    virtual void log(Bomb&) = 0;
};