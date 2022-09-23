#include "BombIterator.h"
#include "MyTools.h"

BombIterator& BombIterator::operator++ (){
    curIdx++;
    if (curIdx == -1)
    {
        curIdx = 0;
    }
    for (; curIdx < vecDynObj.size(); curIdx++)
    {
        Bomb* pBomb = dynamic_cast<Bomb*>(vecDynObj[curIdx]);
        if (pBomb != nullptr)
        {
            ptr = pBomb;
            break;
        }
    }
    if (curIdx == vecDynObj.size())
        this->reset();
    return *this;
};

BombIterator& BombIterator::operator-- (){
    if (curIdx == -1)
    {
        curIdx = vecDynObj.size() - 1;
    }
    else 
    {
        curIdx--;
    }
    for (; curIdx >= 0; curIdx--)
    {
        Bomb* pBomb = dynamic_cast<Bomb*>(vecDynObj[curIdx]);
        if (pBomb != nullptr)
        {
            ptr = pBomb;
            break;
        }
    }

    if (curIdx == -1)
    {
        this->reset();
    }
    return *this;
};

Bomb* BombIterator::operator* (){
    return ptr;
};


bool BombIterator::operator== (BombIterator it){
    if (it.curIdx == this->curIdx && it.ptr == this->ptr && it.vecDynObj == this->vecDynObj){
        return true;
    }
    return false;
};

bool BombIterator::operator!= (BombIterator it){
    return !(*this == it);
};