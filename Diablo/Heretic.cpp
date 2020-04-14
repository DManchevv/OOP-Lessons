#include "Heretic.h"
#include <string>
void Heretic::Attack(Entity& character)
{
	double damageToInflict = min(character.getStrength(), character.getIntellect()) + getIntellect();
	Entity::Attack(character, damageToInflict);
}

void Heretic::print()
{
	cout << "Heretic " << getName() << " : " << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
}
