#pragma once

#include "Mediator.h"
#include "NotifiableObject.h"

class TanksPlaneMediator : public Mediator {
private:
    std::vector<NotifiableObject*> _notifiableObjects;
public:
    void Notify(const NotifiableObject* from, std::string info) override;
    void AddNotifiableObject(NotifiableObject* newNotifiableObject) override;
};