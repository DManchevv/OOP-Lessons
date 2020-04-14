#include "Demon.h"
#include <string>
void Demon::Attack(Entity& character)
{
	// The demon alternates his attacks between Heretic attack and Skeleton attack.
	if (UseHereticAttack) {
		double damageToInflict = min(character.getStrength(), character.getIntellect()) + getIntellect();
		Entity::Attack(character, damageToInflict);	
	}
	else {
		double damageToInflict = getStrength() + character.getIntellect() / 10;
		Entity::Attack(character, damageToInflict);
	}
	UseHereticAttack = !UseHereticAttack;
}

void Demon::print()
{
	cout << "Demon " << getName() << " : " << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
}
