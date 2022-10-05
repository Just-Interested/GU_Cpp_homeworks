#pragma once

#include "Observer.h"

class Observable {
    virtual void AddObserver(Observer*) = 0;
    virtual void RemoveObserver(Observer*) = 0;
};