#pragma once
#include "Tile.h"
class Field {
public:
	Tile** PlayingField;
	int Size;
	int RemainingEnemies;
	int amountOfDemons;
	int amountOfNecromancer;
	int amountOfHeretics;
	int amountOfSkeletons;
	Field();
	~Field();
};
