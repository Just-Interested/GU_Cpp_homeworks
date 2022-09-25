#include "CollisionDetectorA.h"

bool CollisionDetectorA::PlaneAndLevelGUICollisionDetect(Plane* pPlane, LevelGUI* pLvlGUI) const {
    return pImpl->DetectPlaneAndLevelGUICollision(pPlane, pLvlGUI);
}

bool CollisionDetectorA::BombsAndGroundCollisionDetect(Bomb* pBomb, Ground* pGround) const {
    return pImpl->DetectBombsAndGroundCollision(pBomb, pGround);
}

std::vector<DestroyableGroundObject*> CollisionDetectorA::DestoyableObjectsCollisionDetect(Bomb* pBomb, std::vector<DestroyableGroundObject*> &pDestoyableObjects) const {
    return pImpl->DetectDestoyableObjectsCollision(pBomb, pDestoyableObjects);
}
