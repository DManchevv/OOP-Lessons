#include "GameState.h"
#include "Constants.h"
#include "Heretic.h"
#include "Necromancer.h"
#include "Demon.h"
#include "Skeleton.h"
#include "Barbarian.h"
#include "BountyHunter.h"
#include "Sorcerer.h"
#include <windows.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <string>
GameState::GameState()
{
	OldX = OldY = 0;
	Playing = false;
}
void GameState::GenerateField()
{
	Constants A;
	cout << "Generating field. Please wait..." << endl;
	for (size_t i = 1; i <= 2; i++) {
		srand((int)time(NULL) + i);
		PlaceEnemy(0, A.getRandomName());
	}
	for (size_t i = 1; i <= 4; i++) {
		srand((int)time(NULL) + i);
		PlaceEnemy(1, A.getRandomName());
	}
	for (size_t i = 1; i <= 3; i++) {
		srand((int)time(NULL) + i);
		PlaceEnemy(2, A.getRandomName());
	}
	for (size_t i = 1; i <= 2; i++) {
		srand((int)time(NULL) + i);
		PlaceEnemy(3, A.getRandomName());
	}
	cout << "Playing Field generated!" << endl;
}

void GameState::PlaceEnemy(int enemyType, string name)
{
	int newX = 0;
	int newY = 0;
	srand((int)time(NULL));
	newX = GetRandomPosition();
	srand((int)time(NULL) + 1);
	newY = GetRandomPosition();
	Tile tile = CurrentField.PlayingField[newX][newY];
	while (tile.EntityOnTile != 0) {
		srand((int)time(NULL));
		newX = GetRandomPosition();
		srand((int)time(NULL) + 1);
		newY = GetRandomPosition();
		tile = CurrentField.PlayingField[newX][newY];
	}
	char whatMonster;
	if (enemyType == 1) {
		CurrentField.PlayingField[newX][newY].Enemy = new Heretic(name);
		CurrentField.PlayingField[newX][newY].Enemy->setDead(false);
		whatMonster = 'H';
	}
	else if (enemyType == 2) {
		CurrentField.PlayingField[newX][newY].Enemy = new Necromancer(name);
		CurrentField.PlayingField[newX][newY].Enemy->setDead(false);
		whatMonster = 'N';
	}
	else if (enemyType == 3) {
		CurrentField.PlayingField[newX][newY].Enemy = new Demon(name);
		CurrentField.PlayingField[newX][newY].Enemy->setDead(false);
		whatMonster = 'D';
	}
	else {
		CurrentField.PlayingField[newX][newY].Enemy = new Skeleton(name);
		CurrentField.PlayingField[newX][newY].Enemy->setDead(false);
		whatMonster = 'S';
	}
	CurrentField.PlayingField[newX][newY].typeOfEnemy = whatMonster;
	CurrentField.PlayingField[newX][newY].EntityOnTile = 2;
}

void GameState::PrintField()
{
	cout << "  ";
	for (int i = 0; i < CurrentField.Size; i++) {
		cout << "  " << i << " ";
	}
	cout << endl;
	cout << "  ";
	for (int i = 0; i < CurrentField.Size * 4 + 1; i++) {
		cout << "_";
	}
	cout << endl;
	for (int i = 0; i < CurrentField.Size; i++) {
		cout << i << " | ";
		for (int j = 0; j < CurrentField.Size; j++) {
			if (CurrentField.PlayingField[i][j].EntityOnTile == 1) {
				cout << "P | ";
			}
			// Getting the type of the class and printing the seventh letter of the char array
			// Explanation: typeid.name() returns char array, class "name"
			// We want to get the first letter of the name
			else if (CurrentField.PlayingField[i][j].EntityOnTile == 2) {
				//cout << typeid(CurrentField.PlayingField[i][j].Enemy).name()[6] << " | ";
				cout << CurrentField.PlayingField[i][j].typeOfEnemy << " | ";
			}
			else {
				cout << "  | ";
			}
		}
	    cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < CurrentField.Size * 4; i++) {
		cout << "_";
	}
	cout << "|  ";
	cout << "Legend: P - Player | S - Skeleton | H - Heretic | N - Necromancer | D - Demon" << endl;
}

int GameState::GetRandomPosition()
{
	int Position;
	do {
		Position = rand() % 10;
	} while (Position == 0);
	int result;
	result = Position;
	return result;
}
void GameState::Play()
{
	if (Playing) {
		return;
	}
	Playing = true;
	OldX = 0;
	OldY = 0;
	CurrentField.PlayingField[0][0].IsPlayerOnTile = true;
	CurrentField.PlayingField[0][0].EntityOnTile = 1;
	cout << "Game started! Good luck and have fun!" << endl;
}

int GameState::Move(int x, int y, Entity* &CurrentPlayer)
{
	if (CurrentField.PlayingField[x][y].IsPlayerOnTile) {
		cout << CurrentPlayer->getName() << " is already on the tile!" << endl;
		return -1;
	}
	CurrentField.PlayingField[x][y].IsPlayerOnTile = true;
	CurrentField.PlayingField[OldX][OldY].IsPlayerOnTile = false;
	CurrentField.PlayingField[OldX][OldY].EntityOnTile = 0;
	if (CurrentField.PlayingField[x][y].EntityOnTile == 2) {
		CurrentField.PlayingField[x][y].EntityOnTile = 12;
	}
	else if (CurrentField.PlayingField[x][y].EntityOnTile == 0) {
		CurrentField.PlayingField[x][y].EntityOnTile = 1;
	}
	OldX = x;
	OldY = y;
	cout << "Moved " << CurrentPlayer->getName() << " to position " << x << " , " << y << endl;
	int result = 0;
	if (CurrentField.PlayingField[x][y].EntityOnTile == 12) {
		//Entity* enemy = &CurrentField.PlayingField[x][y].Enemy;
		if (CurrentField.PlayingField[x][y].typeOfEnemy == 'D') {
			cout << CurrentPlayer->getName() << " encountered a Demon " << CurrentField.PlayingField[x][y].Enemy->getName() << endl;
		}
		else if (CurrentField.PlayingField[x][y].typeOfEnemy == 'H') {
			cout << CurrentPlayer->getName() << " encountered a Heretic " << CurrentField.PlayingField[x][y].Enemy->getName() << endl;
		}
		else if (CurrentField.PlayingField[x][y].typeOfEnemy == 'S') {
			cout << CurrentPlayer->getName() << " encountered a Skeleton " << CurrentField.PlayingField[x][y].Enemy->getName() << endl;
		}
		else {
			cout << CurrentPlayer->getName() << " encountered a Necromancer " << CurrentField.PlayingField[x][y].Enemy->getName() << endl;
		}
		CurrentField.PlayingField[x][y].Enemy->print();
		do {
			if (!CurrentPlayer->getInCombat()) {
				CurrentPlayer->StartCombat();
				CurrentField.PlayingField[x][y].Enemy->StartCombat();
			}
			CurrentPlayer->Attack(*CurrentField.PlayingField[x][y].Enemy);
			if (CurrentField.PlayingField[x][y].Enemy->getHealthPoints() > 0) {
				CurrentField.PlayingField[x][y].Enemy->Attack(*CurrentPlayer);
			}
			cout << endl;
			Sleep(2000);
		} while (!CurrentPlayer->getDead() and !CurrentField.PlayingField[x][y].Enemy->getDead());
		if (CurrentPlayer->getDead()) {
			CurrentPlayer->EndCombat();
			CurrentField.PlayingField[x][y].Enemy->EndCombat();
			cout << CurrentPlayer->getName() << " was annihilated and died a gruesome death. Game OVER!" << endl;
			exit(0);
			result = -2;
		}
		else if (CurrentField.PlayingField[x][y].Enemy->getDead()) {
			CurrentPlayer->EndCombat();
			CurrentField.PlayingField[x][y].Enemy->EndCombat();
			CurrentField.PlayingField[x][y].EntityOnTile = 1;
			CurrentField.RemainingEnemies--;
		}
		if (CurrentField.RemainingEnemies > 0) {
			CurrentPlayer->print();
			cout << "Remaining enemies: " << CurrentField.RemainingEnemies << endl;
		}
		else {
			cout << "Congratulations! You won the game! Final stats: " << endl;
			CurrentPlayer->print();
			exit(0);
			result = 1;
		}
	}
	return result;
}