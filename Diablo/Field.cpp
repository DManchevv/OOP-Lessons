#include "Field.h"
Field::Field() {
	Size = 10;
	RemainingEnemies = 11;
	PlayingField = new Tile*[10];
	for (int i = 0; i < 10; i++) {
		PlayingField[i] = new Tile[10];
	}
	amountOfDemons = 2;
	amountOfHeretics = 4;
	amountOfNecromancer = 3;
	amountOfSkeletons = 2;
	RemainingEnemies = amountOfDemons + amountOfNecromancer + amountOfHeretics + amountOfSkeletons;
}


Field::~Field()
{
	delete[] PlayingField;
}
