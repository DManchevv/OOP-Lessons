#pragma once
#include "Enemy.h"
#include "Skeleton.h"
#include <queue>
using namespace std;
class Necromancer : public Enemy {
private:
	int CombatRound = 0;
public:
	queue <Skeleton> SkeletonArmy;
	Necromancer(string name) : Enemy(name, 75 , 3, 15) {}
	void Attack(Entity& character) override;
	void print() override;
};
