#pragma once
#include "Map.h"
#include "Music.h"
#include "Menu.h"

//class containing all game methods and info
class Game {
public:
	Game();
	~Game();
	//initializes the interface
	bool initialize();
	//initializes SDL and graphics parameters
	bool initSDL();
	bool initRenderer();

	bool loadSurface(SDL_Surface** surface, char* path);
	bool loadTextures();
	void mapColors();
	void initTime();

	void freeSpace();
	void update();
	void render();
	void handleEvents();

	void cleanSDL();

	void drawMenu();
	void drawVictoryMenu();

	//whole game loop
	void gameLoop();

	void setQuit(const bool value);

	//creates the map on screen and in memory
	void createMap();
	void allocMap();
	void setVictory(const bool value);

	void gameStart();
	
	Map* getMap();

	SDL_Surface* getScreen();

	void loadEnding();

private:
	int countMap;
	const int MAP_COUNT = 10;
	int currentMapID;
	//used for window and renderer setup
	int rc;

	// t1 - starting time, t2 - current time (all in miliseconds)
	int t1, t2;

	// delta - t2-t1 in seconds
	// worldTime - time since program started (seconds)
	double delta, worldTime;

	bool victory = 0;

	//used for quitting the game
	bool quit;
	
	//used for handling colours
	int black, green, red, blue;
	int coolBlue, bgcolor;

	//used for storing text used in menu
	char text[128];
	bool checkMap[11];

	SDL_Surface *charset;

	Map* gameMap_;
	Mus* mus;
	Img* img;
	Menu* menu;
};
