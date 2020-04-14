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
class BountyHunter : public Character {
	double Agility = 10;
	int AttackCounter = 0;

public:
	BountyHunter(string name) : Character(name, 250, 8, 3) {
		setDead(false);
	};

	void EndCombat() override;
	void Attack(Entity& enemy) override;
	void print() override;
private:
	void LevelUp();
};
