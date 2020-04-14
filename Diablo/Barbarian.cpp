#include "Barbarian.h"
#include <string>
void Barbarian::StartCombat()
{
	{
		if (getInCombat()) {
			return;
		}
		Entity::StartCombat();
		// Get % damage increase. For example, at 100 Rage a 20% dmg increase would be in order,
		// so the Enrage will be 1.2.
		double valueToAdd = (Rage / 5) / 100;
		Enrage += valueToAdd;
		cout << "Barbarian " << getName() << " started the battle with a " << valueToAdd * 100 << "% enrage bonus." << endl;
		// Spend all the rage.
		Rage = 0;
	}
}

void Barbarian::EndCombat()
{
	if (!getInCombat()) {
		return;
	}
	Entity::EndCombat();
	// The enrage lasts for the entire battle, but not for the next one.
	Enrage = 1;
	if (!getDead()) {
		EnemiesKilled++;
		if (EnemiesKilled >= EnemiesNeededToKill) {
			LevelUp();
		}
	}
}

void Barbarian::Attack(Entity& enemy)
{
	StartCombat();
	enemy.StartCombat();
	double damageToInflict = (getStrength() + 0.2 * getIntellect()) * Enrage;
	if (execute and executeIndex < 3) {
		damageToInflict += 60;
		execute = false;
		executeIndex++;
	}
	Entity::Attack(enemy, damageToInflict);
	// Rage can't be above 100
	Rage = min(100.0, Rage + 2);
}

void Barbarian::Defend(double &damageToInflict)
{
	Entity::Defend(damageToInflict);
	// Rage can't be above 100
	Rage = min(100.0, Rage + 3);
}

void Barbarian::print()
{
	cout << "Barbarian " << getName() << " : " << endl;
	cout << "\tLevel: " << Level << endl;
	cout << "\tEnemies needed for level up: " << EnemiesKilled << " / " << EnemiesNeededToKill << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
	cout << "\tRage: " << Rage << endl;
}

void Barbarian::LevelUp()
{
	// We don't override Character.LevelUp because it requires initial values,
	// and we don't know them there, because the character can be multiple classes.
	Character::LevelUp(10, 3);
	cout << getName() << " has leveled up to level " << Level << "! New Stats: " << endl;
	if (Level == 3) {
		cout << "You unlocked a new spell: Enraged Regeneration." << endl;
	}
}

void Barbarian::regeneration()
{
	int bonusHealth = 100 + ceil(Rage / 4);
	setHealthPoints(getHealthPoints() + bonusHealth);
	Rage = 0;
	regenIndex++;
	cout << "Successfully healed for " << bonusHealth << "." << endl;
}