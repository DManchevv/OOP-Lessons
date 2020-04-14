#pragma once
#include <iostream>
#include "Character.h"
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
/*
	Basically Warrior in World of Warcraft. Builds up Rage during the battle,
	then uses all of it at the start of the next one to gain a % increase in damage dealt.
	High strength, low intellect.
*/
class Barbarian : public Character {
	double Rage = 0;
	double Enrage = 1;
	void LevelUp();
public:
	Barbarian(string name) : Character(name, 350, 10, 3) {
		setDead(false);
	}
	bool execute = false;
	int executeIndex = 0;
	int regenIndex = 0;
	void StartCombat() override;
	void EndCombat() override;
	void Attack(Entity& enemy) override;
	void Defend(double &damageToInflict) override;
	void print() override;
	void regeneration();
};
