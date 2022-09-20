#pragma once

#include "AbstractCommand.h"
#include "DynamicObject.h"
#include <vector>

class DeleteDynamicObjCommand : public AbstractCommand {
private:
    DynamicObject* obj;
    std::vector<DynamicObject*>* vecDynamicObj;
public:
    DeleteDynamicObjCommand(DynamicObject* _obj, std::vector<DynamicObject*>& _vecDynamicObj){
        obj = _obj;
        vecDynamicObj = &_vecDynamicObj;
    };
    void Execute() override;
};