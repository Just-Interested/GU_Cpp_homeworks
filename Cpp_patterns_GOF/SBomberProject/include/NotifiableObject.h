#pragma once

#include <iostream>

class Mediator;

class NotifiableObject {
public:
    virtual void BeNotified(std::string info) = 0;
    static Mediator* pMediator;   
};