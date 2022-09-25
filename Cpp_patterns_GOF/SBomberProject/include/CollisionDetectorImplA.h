#pragma once

#include "CollisionDetectorImpl.h"

class CollisionDetectorImplA : public CollisionDetectorImpl {
public:
    virtual bool DetectPlaneAndLevelGUICollision(Plane* pPlane, LevelGUI* pLvlGUI) override;
    virtual bool DetectBombsAndGroundCollision(Bomb* pBomb, Ground* pGround) override;
    virtual std::vector<DestroyableGroundObject*> DetectDestoyableObjectsCollision(Bomb* pBomb, std::vector<DestroyableGroundObject*> &pDestoyableObjects) override;
};