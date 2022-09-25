#include "CollisionDetectorImplA.h"

bool CollisionDetectorImplA::DetectPlaneAndLevelGUICollision(Plane* pPlane, LevelGUI* pLvlGUI) {
    if (pPlane->GetX() >= pLvlGUI->GetFinishX())
        return true;
    return false;
};

bool CollisionDetectorImplA::DetectBombsAndGroundCollision(Bomb* pBomb, Ground* pGround) {
    if (pBomb->GetY() >= pGround->GetY())
        return true;
    return false;
};

std::vector<DestroyableGroundObject*> CollisionDetectorImplA::DetectDestoyableObjectsCollision(Bomb* pBomb, std::vector<DestroyableGroundObject*> &pDestoyableObjects) {
    std::vector<DestroyableGroundObject*> objsToBeDestoyed;
    double bombSize = pBomb->GetWidth();
    double x1 = pBomb->GetX() - (bombSize / 2);
    double x2 = x1 + bombSize;
    for (size_t i = 0; i < pDestoyableObjects.size(); i++)
    {
        if (pDestoyableObjects[i]->isInside(x1, x2))
            objsToBeDestoyed.push_back(pDestoyableObjects[i]);
    }
    return objsToBeDestoyed;
};