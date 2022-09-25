#pragma once

#include <vector>

#include "Bomb.h"
#include "Ground.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "DestroyableGroundObject.h"    


class CollisionDetectorImpl {
public:
    virtual ~CollisionDetectorImpl(){};
    virtual bool DetectPlaneAndLevelGUICollision(Plane* pPlane, LevelGUI* pLvlGUI) = 0;
    virtual bool DetectBombsAndGroundCollision(Bomb* pBomb, Ground* pGround) = 0;
    virtual std::vector<DestroyableGroundObject*> DetectDestoyableObjectsCollision(Bomb* pBomb, std::vector<DestroyableGroundObject*> &pDestoyableObjects) = 0;
};