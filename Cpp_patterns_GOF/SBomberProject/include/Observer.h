#pragma once

class Observer {
public:
    virtual bool HandleInsideCheck(double x, double y) const = 0; 
};