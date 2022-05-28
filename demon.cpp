#include "demon.h"
#include "Map.h"

Demon::Demon(int x, int y, Map* map) : Item(x, y), selfMap_(map) { type = 'D'; }

char* Demon::getPath() { return IMAGE_PATH; }

bool Demon::Collide(Directions dir) {
    int tmpX = yPosition;
	int tmpY = xPosition;

	switch (dir) {
        case UP:
            tmpY--;
            break;
        case DOWN:
            tmpY++;
            break;
        case LEFT:
            tmpX--;
            break;
        case RIGHT:
            tmpX++;
            break;
	}

    int mapWidth = selfMap_->getMapWidth();
    int mapHeight = selfMap_->getMapHeight();

    if (tmpX < 0 || tmpX > mapWidth || tmpY < 0 || tmpY > mapHeight) {
        return false;
    }

    Item* itemOnPosition;
    itemOnPosition = selfMap_->getItem(tmpX, tmpY);

    char type = itemOnPosition->getType();

    if (type == ' ') {
        return true;
    }

    if (type == 'F') {
		return true;
	}

    if (type == 'W') {
		return true;
	}

    if (type == 't') {
		return true;
	}

    if (type == 'B') {
		return true;
	}

	//can't move
	return false;
}