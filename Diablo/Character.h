#pragma once
#include "Entity.h"
#include "Constants.h"
class Character : public Entity {
protected:
	int Level = 1;
	int EnemiesKilled = 0;
	int EnemiesNeededToKill = 2;
public:
	Character(string name, double hp, int strength, int intellect) : Entity(name, hp, strength, intellect) {}
	void LevelUp(const int initialStrength, const int initialIntellect);
	const int getLevel() const;
};
