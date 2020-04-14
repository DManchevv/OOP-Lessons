#include "Sorcerer.h"
#include <string>
void Sorcerer::Attack(Entity& entity)
{
	if (Mana < 10) {
		cout << getName() << " cannot attack because his mana is too low." << endl;
		return;
	}

	double baseDamageToInflict = (getStrength()*2 + 0.2 * getIntellect()) / 2;
	double damageToInflict = (baseDamageToInflict + Mana / 100 * 0.75) * getIntellect() * 0.5;
	if (pyroblast and pyroblastIndex < 2) {
		damageToInflict += 200;
		pyroblast = false;
		pyroblastIndex++;
	}
	Entity::Attack(entity, damageToInflict);
	// Reduce the mana with each attack
	Mana = max(0.0, Mana - 10);
	cout << "Remaining mana: " << Mana << "%" << endl;
}

void Sorcerer::EndCombat()
{
	if (!getInCombat()) {
		return;
	}
	Entity::EndCombat();
	
	// Ensure mana is never above 100
	Mana = min(100.0, Mana + 100);
	cout << "Mana refilled to " << Mana << "%" << endl;
	if (!getDead()) {
		EnemiesKilled++;
		if (EnemiesKilled >= EnemiesNeededToKill) {
			LevelUp();
		}
	}
}

void Sorcerer::LevelUp()
{
	// We don't override Character.LevelUp because it requires initial values,
	// and we don't know them there, because the character can be multiple classes.
	Character::LevelUp(4, 10);
	cout << getName() << " has leveled up to level " << Level << "! New Stats: " << endl;
	if (Level == 3) {
		cout << "You unlocked a new spell: Pyroblast." << endl;
	}
}
void Sorcerer::Defend(double& inflictedDamage) {
	if (absorb != 0 and absorbIndex < 3) {
		if (inflictedDamage < absorb) {
			absorb -= inflictedDamage;
			inflictedDamage = 0;
		}
		else {
			inflictedDamage -= absorb;
			absorb = 0;
		}
		cout << "Amount of absorb left: " << absorb << "." << endl;
	}
}
void Sorcerer::print()
{
	cout << "Sorcerer " << getName() << " : " << endl;
	cout << "\tLevel: " << Level << endl;
	cout << "\tEnemies needed for level up: " << EnemiesKilled << " / " << EnemiesNeededToKill << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
}
