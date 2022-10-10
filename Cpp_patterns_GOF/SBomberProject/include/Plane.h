#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    virtual void DrawBody() const = 0;
    virtual void DrawWings() const = 0;
    virtual void DrawTail() const = 0;

private:

};

