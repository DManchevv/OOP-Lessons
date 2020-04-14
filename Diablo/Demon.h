#pragma once
#include "Enemy.h"
/*
	Summary:
	Whether the demon should use the heretic's attack.
	If set to false, the demon just uses the skeleton's attack,
	effectively alternating between them.
*/
class Demon : public Enemy{
	bool UseHereticAttack = false;
public:
	Demon(string name) : Enemy(name, 350, 12, 10) {}
	void Attack(Entity& character) override;
	void print() override;
};
