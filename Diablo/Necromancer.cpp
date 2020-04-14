#include "Necromancer.h"
#include "Constants.h"
#include <string>

void Necromancer::Attack(Entity& character)
{
	// Summon a skeleton the first and every sixth round.
	// Increased the spawn rate of skeletons to one every 10 attacks because the fight was taking too long
	// when the player is a barbarian.
	if (CombatRound == 0 or (CombatRound + 1) % 8 == 0) {
		Constants A;
		string skeletonName = "Skeleton thrall " + A.getRandomName();
		Skeleton newSkeleton(skeletonName);
		newSkeleton.setDead(false);
		SkeletonArmy.push(newSkeleton);
		cout << getName() << " summoned a new " << skeletonName << "!" << endl;
	}
	double damageToInflict = 0;
	if (SkeletonArmy.size() > 0) {
		damageToInflict = SkeletonArmy.front().getHealthPoints() / 10;
	}
	damageToInflict += getIntellect();
	Entity::Attack(character, damageToInflict);
	CombatRound++;
}

void Necromancer::print()
{
	cout << "Necromancer " << getName() << " : " << endl;
	cout << "\tHealth: " << getHealthPoints() << endl;
	cout << "\tStrength: " << getStrength() << endl;
	cout << "\tIntellect: " << getIntellect() << endl;
	cout << "\tSkeleton thralls: " << endl;
 queue <Skeleton> copy;
	copy = SkeletonArmy;
	while (!copy.empty()) {
		copy.front().print();
		copy.pop();
	}
}
