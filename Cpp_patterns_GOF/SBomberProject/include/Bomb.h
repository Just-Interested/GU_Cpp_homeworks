#pragma once

#include "AbstractBomb.h"

class Bomb : public AbstractBomb
{
public:

	static const uint16_t BombCost = 10; 

	void Draw() const override;

private:

};

