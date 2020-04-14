#pragma once
#include "Field.h"
class GameState {
	int OldX;
	int OldY;
	bool Playing;
public:
	Field CurrentField;
	GameState();
	void GenerateField();
	void PlaceEnemy(int enemyType, string name);
	void PrintField();
	int GetRandomPosition();
	void Play();
	int Move(int x, int y, Entity* &CurrentPlayer);
};
