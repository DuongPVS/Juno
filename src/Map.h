#pragma once
#include "Item.h"
#include "Crate.h"
#include "EndPoint.h"
#include "Grass.h"
#include "Wall.h"
#include "Player.h"
#include "Ground.h"
#include "demon.h"
#include "Key.h"
#include "Treasure.h"
#include "Trap.h"
#include "Boss.h"
#include "Directions.h"

class Game;

struct Coords {
	int x;
	int y;
};

class Map {
public:
	Map(int ID, Game* game_);
	~Map();
	Coords itemToMapCoords(int itemX, int itemY);
	void drawMap();
	// doesn't put any items inside
	void allocateItemMap();
	int getIDSize();
	char* getMapPath();
	bool loadMap();
	void drawPlayer();

	Player* getPlayer();
	Item* getItem(int x, int y);
	int getMapHeight();
	int getMapWidth();
	int getID();

	void moveCrate(Item* crate, Directions dir);
	void moveDemon(Item* demon, Directions dir);
	void moveKey(Item* key);
	void moveTreasure(Item* treasure);

	bool getTakeKey();

private:
	// used for switching through maps
	int mapID;
	bool isTakeKey;

	const int SPRITE_SIZE = 32;

	// map sizes
	int mapWidth = 0, mapHeight = 0;

	Item*** itemMap;
	Player* player;
	Game* selfGame_;
};
