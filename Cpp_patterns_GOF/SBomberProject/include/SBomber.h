#pragma once

#include <vector>

#include "SbomberImpl.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return pImpl->GetExitFlag(); }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    // void CheckPlaneAndLevelGUI();
    // void CheckBombsAndGround();
    // void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    // void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    // void __fastcall DeleteStaticObj(GameObject* pObj);

    // Ground * FindGround() const;
    // Plane * FindPlane() const;
    // LevelGUI * FindLevelGUI() const;
    // std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    // std::vector<Bomb*> FindAllBombs() const;

    // void DropBomb();
    
    SBomberImpl* pImpl;
};