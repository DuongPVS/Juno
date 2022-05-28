#include "Trap.h"

Trap::Trap(int x, int y) : Item(x,y) {
	type = 't';
}

char * Trap::getPath()
{
	return IMAGE_PATH;
}

bool Trap::Collide(Directions dir) {
	//player can't be adjacent to grass either way
	return true;
}