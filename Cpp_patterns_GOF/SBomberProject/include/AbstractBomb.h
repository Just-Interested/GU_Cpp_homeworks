#pragma once

#include "DynamicObject.h"

class AbstractBomb : public DynamicObject
{
public:

	virtual void Draw() const = 0;

private:

};