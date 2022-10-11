
#include "SBomber.h"

SBomber::SBomber() : pImpl(new SBomberImpl) {}

SBomber::~SBomber()
{
    delete pImpl;
}

void SBomber::MoveObjects()
{
    pImpl->MoveObjects();
};

void SBomber::CheckObjects()
{
    pImpl->CheckObjects();
};

// void SBomber::CheckPlaneAndLevelGUI()
// {
//     pImpl->CheckPlaneAndLevelGUI();
// }

// void SBomber::CheckBombsAndGround() 
// {
//     pImpl->CheckBombsAndGround();
// }

// void SBomber::CheckDestoyableObjects(Bomb * pBomb)
// {
//     pImpl->CheckDestoyableObjects(pBomb);
// }

// void SBomber::DeleteDynamicObj(DynamicObject* pObj)
// {
//     pImpl->DeleteDynamicObj(pObj);
// }

// void SBomber::DeleteStaticObj(GameObject* pObj)
// {
//     pImpl->DeleteStaticObj(pObj);
// }

// std::vector<DestroyableGroundObject*> SBomber::FindDestoyableGroundObjects() const
// {
//     return pImpl->FindDestoyableGroundObjects();
// }

// Ground* SBomber::FindGround() const
// {
//     return pImpl->FindGround();
// }

// std::vector<Bomb*> SBomber::FindAllBombs() const
// {
//     return pImpl->FindAllBombs();
// }

// Plane* SBomber::FindPlane() const
// {
//     return pImpl->FindPlane();
// }

// LevelGUI* SBomber::FindLevelGUI() const
// {
//     return pImpl->FindLevelGUI();
// }

void SBomber::ProcessKBHit()
{
    pImpl->ProcessKBHit();
}

void SBomber::DrawFrame()
{
    pImpl->DrawFrame();
}

void SBomber::TimeStart()
{
    pImpl->TimeStart();
}

void SBomber::TimeFinish()
{
    pImpl->TimeFinish();
}

// void SBomber::DropBomb()
// {
//     pImpl->DropBomb();
// }
