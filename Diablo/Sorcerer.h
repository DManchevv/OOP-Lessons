#pragma once
#include "Character.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Sorcerer : public Character {
	double Mana = 100;
public:
	Sorcerer(string name) : Character(name, 150, 1, 10) {
		setDead(false);
	}
	int absorb = 0;
	int absorbIndex = 0;
	bool pyroblast = false;
	int pyroblastIndex = 0;
	void Attack(Entity& entity) override;
	void EndCombat() override;
	void Defend(double& damageToInflict) override;
	void LevelUp();
	void print() override;
};
