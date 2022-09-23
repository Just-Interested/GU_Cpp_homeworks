#pragma once

#include <vector>

#include "Bomb.h"

class BombIterator {
private:
    const std::vector<DynamicObject*>& vecDynObj;
    int curIdx;
    Bomb* ptr;
public:

    BombIterator(const std::vector<DynamicObject*>& _vecDynObj) : vecDynObj(_vecDynObj), curIdx(-1), ptr(nullptr) {++(*this);};
    void reset() { curIdx = -1; ptr = nullptr;};
    BombIterator& operator++ ();
    BombIterator& operator-- ();
    Bomb* operator* ();
    bool operator== (BombIterator it);
    bool operator!= (BombIterator it);
};