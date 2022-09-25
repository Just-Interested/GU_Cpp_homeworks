#pragma once

#include "CollisionDetectorImpl.h"

class CollisionDetector {
protected:
    CollisionDetectorImpl* pImpl;
public:
    CollisionDetector(CollisionDetectorImpl* _pImpl) : pImpl(_pImpl) {};
    virtual ~CollisionDetector() {
        delete pImpl;
    };
    virtual bool PlaneAndLevelGUICollisionDetect(Plane* pPlane, LevelGUI* pLvlGUI) const = 0;
    virtual bool BombsAndGroundCollisionDetect(Bomb* pBomb, Ground* pGround) const = 0;
    virtual std::vector<DestroyableGroundObject*> DestoyableObjectsCollisionDetect(Bomb* pBomb, std::vector<DestroyableGroundObject*> &pDestoyableObjects) const = 0;
};