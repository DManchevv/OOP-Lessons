#include "Character.h"
void Character::LevelUp(const int initialStrength, const int initialIntellect)
{
	// Increase HP by 10% always.
	const int HP = round(getHealthPoints() * 1.1);
	setHealthPoints(HP);
	// Increase all stats by the formula: currentStat + ((initialStat / allStats) * 2)
	double statsValue = getStrength() + getIntellect();
	setStrength(getStrength() + round(getStrength() + (initialStrength / statsValue) * 2));
	setIntellect(getIntellect() + round(getIntellect() + (initialIntellect / statsValue) * 2));
	Level++;
	// Reset the counter
	EnemiesKilled = 0;
	EnemiesNeededToKill = pow(2, Level);
}

const int Character::getLevel() const
{
	return Level;
}
