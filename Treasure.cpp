#include "Treasure.h"

Treasure::Treasure(int x, int y) : Item(x,y) {
	type = 'T';
}

char * Treasure::getPath()
{
	return IMAGE_PATH;
}

bool Treasure::Collide(Directions dir) {
	//player can't be adjacent to grass either way
	return true;
}