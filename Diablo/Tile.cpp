#include "Tile.h"

Entity* Tile::getEnemy() {
	return Enemy;
}
void Tile::setEnemy(Entity newEnemy) {
	Enemy = &newEnemy;
}