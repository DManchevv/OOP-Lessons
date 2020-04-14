#include "Entity.h"
#include "Necromancer.h"
#include "Constants.h"
#include <string>
using namespace std;

Entity::Entity()
{
	Name = "";
	HealthPoints = 0;
	Strength = Intellect = 1;
	Dead = false;
	InCombat = false;
}

Entity::Entity(string name, const double hp, const double strength, const double intellect)
{
	if (name == "") {
		cout << "Name is empty!" << endl;
	}
	else {
		Name = name;
		HealthPoints = max(0.0, hp);
		Strength = max(0.0, strength);
		Intellect = max(0.0, intellect);
	}
}

void Entity::setName(string newName)
{
	Name = newName;
}

void Entity::setHealthPoints(const double newHealthPoints)
{
	HealthPoints = newHealthPoints;
}

void Entity::setStrength(const double newStrength)
{
	Strength = newStrength;
}

void Entity::setIntellect(const double newIntellect)
{
	Intellect = newIntellect;
}

void Entity::setDead(const bool newDead)
{
	Dead = newDead;
}

void Entity::setInCombat(const bool newInCombat)
{
	InCombat = newInCombat;
}

string Entity::getName()
{
	return Name;
}

const double Entity::getHealthPoints() const
{
	return HealthPoints;
}

const double Entity::getStrength() const
{
	return Strength;
}

const double Entity::getIntellect() const
{
	return Intellect;
}

const bool Entity::getDead() const
{
	return Dead;
}

const bool Entity::getInCombat() const
{
	return InCombat;
}

void Entity::Attack(Entity& entity)
{
	double damageToInflict = Strength + 0.2 * Intellect;
	Attack(entity, damageToInflict);
}

/* Summary:
		Attack the entity with the provided damage.
		The being to be attacked
		The base damage to be inflicted
*/
void Entity::Attack(Entity& entity, double damageToInflict)
{
	// Necromancers use their skeleton army to take the attacks for them,
	// so we need custom logic for it. However, if the necromancer
	// has no skeletons, we attack it directly.
	string a = typeid(entity).name();
	if (a == "class Necromancer" and static_cast<Necromancer*>(&entity)->SkeletonArmy.size() > 0) {
		Entity* skeleton = &static_cast<Necromancer*>(&entity)->SkeletonArmy.front();
		Attack(*skeleton, damageToInflict);
		if (skeleton->getDead()) static_cast<Necromancer*>(&entity)->SkeletonArmy.pop();
	}
	else {
		// Reduce the damage by the entity's strength
		entity.Defend(damageToInflict);
		// Reduce the HP, but make sure the damage is no bigger than the entity's own HP.
		// This way if the attacker overkills the victim would have 0 HP left, instead of negative.
		entity.setHealthPoints(round(max(0.0, entity.getHealthPoints() - damageToInflict)));
		cout << this->getName() << " hit " << entity.getName() << " for " << damageToInflict << ". " << entity.getName() << " has " <<
			entity.getHealthPoints() << " HP left." << endl;
		if (entity.getHealthPoints() <= 0) {
			entity.setDead(true);
			cout << entity.getName() << " was completely destroyed by " << this->getName() << "." << endl;
		}
	}
}

void Entity::Defend(double& damageToInflict)
{
	// Reduce the damage by the entity's Strength.
	// Ensure the damage will never fall below 0.
	damageToInflict = round(max(0.0, damageToInflict - Strength / 2));
}

void Entity::StartCombat()
{
	InCombat = true;
}

void Entity::EndCombat()
{
	InCombat = false;
}

void Entity::print() {}