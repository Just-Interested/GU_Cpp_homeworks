#pragma once

#include <vector>

#include "NotifiableObject.h"

class Mediator {
private:
    std::vector<NotifiableObject*> _notifiableObjects;
public:
    virtual void Notify(const NotifiableObject* from, std::string info) = 0;
    virtual void AddNotifiableObject(NotifiableObject* newNotifiableObject) = 0;
};