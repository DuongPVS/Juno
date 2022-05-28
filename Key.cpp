#include "Key.h"

Key::Key(int x, int y) : Item(x,y) {
	type = 'K';
}

char * Key::getPath()
{
	return IMAGE_PATH;
}

bool Key::Collide(Directions dir) {
	//player can't be adjacent to grass either way
	return true;
}