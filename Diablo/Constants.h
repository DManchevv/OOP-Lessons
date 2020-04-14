#pragma once
#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Constants {
public:
	string RandomNames[50] = { "Robby", "Saturnina", "Sharyl", "Kasie", "Magnolia", "Fairy",
			"Britni","Flora", "Loyd", "Thea", "Cornelia", "Keely", "Graig", "Armand", "Ismael", "Doloris", "Bennett", "Veola",
			"Allegra", "Nakisha", "Edmundo", "Tajuana", "Kacy", "Eugenia", "Brittni", "Hye", "Reiko", "Rosaline", "Ellen",
			"Kristal", "Ignacio", "Manda", "Dewitt", "Karla", "Marylouise", "Kimberlie", "Noemi", "Yolanda", "Ava", "Jerry",
			"Kiyoko", "Katherin", "Alecia", "Vincent", "Denese", "Kristine", "Julianne", "Alana", "Billi", "Claribel" };
	string getRandomName() {
		int random = rand() % 50;
		return RandomNames[random];
	}
};
