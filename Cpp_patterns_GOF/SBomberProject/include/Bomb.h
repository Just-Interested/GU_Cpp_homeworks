#pragma once

#include <vector>

#include "DynamicObject.h"
#include "Observable.h"
#include "DestroyableGroundObject.h"

class Visitor;

class Bomb : public DynamicObject, public Observable
{
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����

	void Draw() const override;

	void Accept(Visitor &) override;

	void AddObserver(Observer*) override;

	void RemoveObserver(Observer*) override;

	DestroyableGroundObject* CheckDestroyableGroundObjects();

private:

	std::vector<Observer*> observers;
};

