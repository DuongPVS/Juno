#include "EndPoint.h"

EndPoint::EndPoint(int x, int y) : Item(x, y) {
	type = 'F';
}

char * EndPoint::getPath()
{
	char firstPart[] = "./img/Ground";
	char *path = new char[18];
	strcpy(path, firstPart);
	path[12] = char((rand() % 6) + 1 + '0');
	path[13] = '.';
	path[14] = 'b';
	path[15] = 'm';
	path[16] = 'p';
	path[17] = '\0';
	return path;
}

bool EndPoint::Collide(Directions dir) {
	//player can move onto endpoint floor
	return true;
}