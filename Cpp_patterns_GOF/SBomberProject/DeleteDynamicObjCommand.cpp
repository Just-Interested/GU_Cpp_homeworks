
#include "DeleteDynamicObjCommand.h"

void DeleteDynamicObjCommand::Execute(){
    auto it = vecDynamicObj->begin();
    for (; it != vecDynamicObj->end(); it++)
    {
        if (*it == obj)
        {
            vecDynamicObj->erase(it);
            break;
        }
    }
}