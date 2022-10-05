#pragma once

#include "Visitor.h"

class LogVisitor : public Visitor {
public:
    void log(Plane&) override;
    void log(Bomb&) override;
};