#include "Boss.h"

Boss::Boss(int x, int y) : Item(x,y) {
	type = 'M';
}

char * Boss::getPath()
{
	return IMAGE_PATH;
}

bool Boss::Collide(Directions dir) {
	// player can't move into wall
	return false;
}