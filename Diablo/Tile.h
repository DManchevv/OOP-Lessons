#pragma once
#include "Entity.h"
class Tile {
private:
public:
	Entity* Enemy;
	bool IsPlayerOnTile;
	int EntityOnTile;
	char typeOfEnemy;
	Tile() {
		EntityOnTile = 0;
		IsPlayerOnTile = false;
	}
	Entity* getEnemy();
	void setEnemy(Entity newEnemy);
};
