#include "Skeleton.h"
#include <string>

void Skeleton::Attack(Entity& character)
{
	double damageToInflict = getStrength() + character.getIntellect() / 10;
	Entity::Attack(character, damageToInflict);
}

void Skeleton::print()
{
	cout << "Skeleton " << getName() << " : " << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
}
