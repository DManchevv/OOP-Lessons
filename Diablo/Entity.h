#pragma once
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>
using namespace std;
class Entity {
	string Name;
	double HealthPoints;
	double Strength;
	double Intellect;
	bool Dead;
	bool InCombat;
public:
	Entity();
	Entity(string name, const double hp, const double strength, const double intellect);
	void setName(string newName);
	void setHealthPoints(const double newHealthPoints);
	void setStrength(const double newStrength);
	void setIntellect(const double newIntellect);
	void setDead(const bool newDead);
	void setInCombat(const bool newInCombat);
	string getName();
	const double getHealthPoints() const;
	const double getStrength() const;
	const double getIntellect() const;
	const bool getDead() const;
	const bool getInCombat() const;
	virtual void Attack(Entity& entity);
	virtual void Attack(Entity& entity, double damageToInflict);
	virtual void Defend(double& damageToInflict);
	virtual void StartCombat();
	virtual void EndCombat();
	virtual void print();
};