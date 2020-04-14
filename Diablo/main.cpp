#include <iostream>
#include <string>
#include "Entity.h"
#include "GameState.h"
#include "Barbarian.h"
#include "BountyHunter.h"
#include "Sorcerer.h"
using namespace std;
string name;
int choice;
bool validation() {
	cin >> choice;
	if (choice < 1 or choice > 3) {
		cout << "Invalid choice. Please choose a character type: " << endl;
		return false;
	}
	return true;
}
bool validation2() {
	cin >> name;
	if (name == " ") {
		cout << "Invalid name. Please choose a new name: " << endl;
		return false;
	}
	return true;
}
int main() {
	try {
		GameState state;
		Entity* CurrentPlayer;
		cout << "WELCOME TO DIABLO 0.5!" << endl;
		cout << "Recommended using fullscreen." << endl;
		cout << "Your goal is to survive and defeat all present enemies. Attack by moving to whatever enemy you wish." << endl;
		cout << "Enemy description:" << endl;
		cout << "Skeleton - the weakest, has low health, does low damage." << endl;
		cout << "Necromancer - periodically summons skeletons, in order to damage the necromancer you have to kill all summoned skeletons. Necromancers have low health." << endl;
		cout << "Heretic - has moderate health, does moderate amount of damage." << endl;
		cout << "Demon - the strongest, hard to kill, every second attack deals a lot of damage. Be careful!" << endl;
		cout << "Please choose a character by typing the number of each class: " << endl;
		cout << "1 - Barbarian - has high health points, high defence skill. Barbarians can cast Execute and Enraged Regeneration." << endl;
		cout << "2 - Sorcerer - has really low health points. Really squishy, does a lot of damage. Sorcerers can cast Absorb and Pyroblast." << endl;
		cout << "3 - Bounty Hunter - has moderate health points, every third attack does a lot of damage." << endl;
		while (true) {
			if (validation()) break;
		}
		cout << "Enter a name for your character: " << endl;
		while (true) {
			if (validation2()) break;
		}
		Barbarian newBarbarian(name);
		Sorcerer newSorcerer(name);
		BountyHunter newBountyHunter(name);
		if (choice == 1) {
			CurrentPlayer = new Barbarian(name);
			CurrentPlayer = &newBarbarian;
		}
		else if (choice == 2) {
			CurrentPlayer = new Sorcerer(name);
			CurrentPlayer = &newSorcerer;
		}
		else {
			CurrentPlayer = new BountyHunter(name);
			CurrentPlayer = &newBountyHunter;
		}
		string characterClass = typeid(*CurrentPlayer).name();
		state.GenerateField();
		state.Play();
		int result = -1000;
		do
		{
			cout << "Please enter a command or enter 'help' for command help: " << endl;
			string command;
			cin >> command;
			if (command == "move") {
				cout << "Enter a position to move to (example: 5 3) : " << endl;
				int x, y;
				cin >> x >> y;
				state.Move(x, y, CurrentPlayer);
			}
			else if (command == "map") {
				state.PrintField();
				result = 0;
			}
			else if (command == "character") {
				CurrentPlayer->print();
			}
			else if (command == "execute" and choice == 1) {
				if (static_cast<Barbarian*>(CurrentPlayer)->executeIndex >= 3) {
					cout << "Limit reached. Execute is no longer available!" << endl;
				}
				else {
					static_cast<Barbarian*>(CurrentPlayer)->execute = true;
					cout << "Execute successfully enabled!" << endl;
				}
			}
			else if (command == "absorb" and choice == 2) {
				if (static_cast<Sorcerer*>(CurrentPlayer)->absorbIndex >= 3) {
					cout << "Limit reached. Absorb is no longer available!" << endl;
				}
				else {
					static_cast <Sorcerer*>(CurrentPlayer)->absorb = 60;
					static_cast <Sorcerer*>(CurrentPlayer)->absorbIndex++;
					cout << "Absorb successfully enabled! Amount of absorb left: 60" << endl;
				}
			}
			else if (command == "pyroblast" and choice == 2 and static_cast<Sorcerer*>(CurrentPlayer)->getLevel() >= 3) {
				if (static_cast<Sorcerer*>(CurrentPlayer)->pyroblastIndex >= 2) {
					cout << "Limit reached. Pyroblast is no longer available!" << endl;
				}
				else {
					static_cast<Sorcerer*>(CurrentPlayer)->pyroblast = true;
					cout << "Pyroblast successfully enabled!" << endl;
				}
			}
			else if (command == "regen" and choice == 1 and static_cast<Barbarian*>(CurrentPlayer)->getLevel() >= 3) {
				if (static_cast<Barbarian*>(CurrentPlayer)->regenIndex >= 1) {
					cout << "Limit reached. Enraged Regeneration is no longer available!" << endl;
				}
				else {
					static_cast<Barbarian*>(CurrentPlayer)->regeneration();
				}
			}
			else if (command == "help") {
				cout << "map - Show the current map with enemies." << endl;
				cout << "character - Display the current character stats." << endl;
				cout << "move - Initiate a move, followed by coordinates." << endl;
				if (characterClass == "class Barbarian") {
					cout << "execute - Your next attack does 60 more damage. "
						 << "Uses left: " << 3 - static_cast<Barbarian*>(CurrentPlayer)->executeIndex << endl;
				}
				if (characterClass == "class Sorcerer") {
					cout << "absorb - You gain absorb shield for 60 damage. "
						 << "Uses left: " << 3 - static_cast <Sorcerer*>(CurrentPlayer)->absorbIndex << endl;
				}
				if (characterClass == "class Sorcerer" and static_cast<Sorcerer*>(CurrentPlayer)->getLevel() >= 3) {
					cout << "pyroblast - You blast the enemy with a big fire boulder for 200 damage. "
						 << "Uses left: " << 2 - static_cast<Sorcerer*>(CurrentPlayer)->pyroblastIndex << endl;
				}
				if (choice == 1 and static_cast<Barbarian*>(CurrentPlayer)->getLevel() >= 3) {
					cout << "regen - You activate enraged regeneration, healing you for 100 and converting all your rage into health. " 
						 << "Uses left: " << 1 - static_cast<Barbarian*>(CurrentPlayer)->regenIndex << "." << endl;
				}
				cout << "exit - Exits the game." << endl;
			}
			else if (command == "exit") {
				cout << "Thank you for playing!" << endl;
				exit(0);
			}
			else cout << "Invalid command!!!!" << endl;
		} while (result != -2 and result != 1);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}