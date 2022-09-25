#pragma once

#include "CollisionDetector.h"
#include "CollisionDetectorImplA.h"

class CollisionDetectorA : public CollisionDetector {
public:
    CollisionDetectorA() : CollisionDetector(new CollisionDetectorImplA) {};
    virtual bool PlaneAndLevelGUICollisionDetect(Plane* pPlane, LevelGUI* pLvlGUI) const override;
    virtual bool BombsAndGroundCollisionDetect(Bomb* pBomb, Ground* pGround) const override;
    virtual std::vector<DestroyableGroundObject*> DestoyableObjectsCollisionDetect(Bomb* pBomb, std::vector<DestroyableGroundObject*> &pDestoyableObjects) const override;

};