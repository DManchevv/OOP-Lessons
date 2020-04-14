#pragma once

#include "Enemy.h"
class Skeleton : public Enemy {
public:
	Skeleton(string name) : Enemy(name, 45, 9, 2) {}
	void Attack(Entity& character) override;
	void print() override;
};
