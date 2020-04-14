#pragma once
#include "Entity.h"
class Enemy : public Entity {
public:
	Enemy(string name, const double hp, const double strength, const double intellect) : Entity(name, hp, strength, intellect) {}
};
