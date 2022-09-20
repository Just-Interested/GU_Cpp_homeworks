#include "DeleteStaticObjCommand.h"


void DeleteStaticObjCommand::Execute(){
    auto it = vecStaticObj->begin();
    for (; it != vecStaticObj->end(); it++)
    {
        if (*it == obj)
        {
            vecStaticObj->erase(it);
            break;
        }
    }
}