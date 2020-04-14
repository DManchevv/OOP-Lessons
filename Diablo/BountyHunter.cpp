#include "BountyHunter.h"
#include <string>
void BountyHunter::Attack(Entity& entity)
{
	double damageToInflict;
	if (AttackCounter == 2)
	{
		// Every third attack hits harder
		damageToInflict = Agility + 0.4 * getIntellect() + 0.6 * getStrength();
	}
	else
	{
		damageToInflict = 0.8 * Agility;
	}

	Entity::Attack(entity, damageToInflict);
	AttackCounter++;
	// Ensure the counter will always be 0, 1 or 2 and always rotate incrementally.
	if (AttackCounter > 2)
	{
		AttackCounter = 0;
	}
}

void BountyHunter::EndCombat()
{
	Entity::EndCombat();
	if (!getDead())
	{
		EnemiesKilled++;
		if (EnemiesKilled >= EnemiesNeededToKill)
		{
			LevelUp();
		}
	}
}

void BountyHunter::LevelUp()
{
	// We don't override Character.LevelUp because it requires initial values,
	// and we don't know them there, because the character can be multiple classes.
	Character::LevelUp(9, 16);
	Agility += 4;
	cout << getName() << " has leveled up to level " << Level << "! New Stats: " << endl;
}

void BountyHunter::print()
{
	cout << "Sorcerer " << getName() << " : " << endl;
	cout << "\tLevel: " << Level << endl;
	cout << "\tEnemies needed for level up: " << EnemiesKilled << " / " << EnemiesNeededToKill << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
	cout << "\tAgility: " << Agility << endl;
}