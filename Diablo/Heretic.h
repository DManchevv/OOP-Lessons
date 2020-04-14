#pragma once
#include "Enemy.h"
class Heretic : public Enemy {
public:
	Heretic(string name) : Enemy(name, 100, 2, 20) {}
	void Attack(Entity& character) override;
	void print() override;
};
