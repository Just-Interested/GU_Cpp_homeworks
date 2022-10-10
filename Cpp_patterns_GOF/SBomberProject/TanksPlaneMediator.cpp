#include "TanksPlaneMediator.h"
#include "MyTools.h"

#include <Windows.h>

void TanksPlaneMediator::AddNotifiableObject(NotifiableObject* newNotifiableObject){
    _notifiableObjects.push_back(newNotifiableObject);
}

void TanksPlaneMediator::Notify(const NotifiableObject* from, std::string info){
    for (auto pItem : _notifiableObjects){
        if (pItem != from)
            pItem->BeNotified(info);
            MyTools::WriteToLog(info);
    }
}