#pragma once

#include "AbstractCommand.h"
#include "DynamicObject.h"
#include "Plane.h"
#include <vector>

class DropBombCommand : public AbstractCommand {
private:
    std::vector<DynamicObject*>* vecDynamicObj;
    Plane* pPlane;
    uint16_t* bombsNumber;
    int16_t* score;
public:
    DropBombCommand(Plane* const _plane, std::vector<DynamicObject*>& _vecDynamicObj, uint16_t& _bombsNumber, int16_t& _score){
        pPlane = _plane;
        vecDynamicObj = &_vecDynamicObj;
        bombsNumber = &_bombsNumber;
        score = &_score;
    }
    void Execute() override;
};