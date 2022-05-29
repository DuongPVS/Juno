#include "Game.h"
#include "InputHandler.h"
#include "loadmp4.h"

Game::Game() { 
	countMap = 0;
	for (int i = 1; i <= 10; i++)
		checkMap[i] = 1;
}

Game::~Game() {}

void Game::allocMap() {
	gameMap_ = new Map(currentMapID, this);
	int step;
	switch (currentMapID) {
		case 1:
			step = 3;
			break;
		case 2:
			step = 23;
			break;
		case 3:
			step = 23;
			break;
		case 4:
			step = 32;
			break;
		case 5:
			step = 22;
			break;
		case 6:
			step = 26;
			break;
		case 7:
			step = 31;
			break;
		case 8:
			step = 38;
			break;
		case 9:
			step = 11;
			break;
		case 10:
			step = 33;
			break;

	}
	gameMap_->getPlayer()->setCountStep(step);
}

void Game::createMap() {
	allocMap();
}

void Game::setVictory(const bool value) {
	victory = value;
}

bool Game::initialize() {
	printf("Program started\n");
	if (!initSDL()) {
		return false;
		printf("Cannot initialize SDL\n");
	}
	if (!loadTextures()) {
		printf("Cannot load textures\n");
		return false;
	}
	mapColors();
	mus = new Mus();
	mus->loadMus();
	img = new Img();
	img->loadgPNGSurface();
	menu = new Menu();
	return true;
}

bool Game::initSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		return false;
	}
	if (!initRenderer()) {
		printf("Cannot initialize renderer\n");
		return false;
	}
	return true;
}

bool Game::initRenderer() {
	rc = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &Sample::window, &Sample::renderer);

	if (rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		return false;
	};

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(Sample::renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderDrawColor(Sample::renderer, 0, 0, 0, 255);

	SDL_SetWindowTitle(Sample::window, "Juno");


	Sample::screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

	Sample::scrtex = SDL_CreateTexture(Sample::renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	//disable mouse cursor in window
	SDL_ShowCursor(SDL_DISABLE);

	return true;
}

bool Game::loadSurface(SDL_Surface** surface, char* path) {
	*surface = SDL_LoadBMP(path);
	if (surface == NULL) {
		printf("SDL_LoadBMP(%s) error: %s\n", path, SDL_GetError());
		cleanSDL();
		SDL_Quit();
		return false;
	}
	return true;
}

bool Game::loadTextures() {
	if (!loadSurface(&charset, "./img/cs8x8.bmp")) {
		printf("Cannot load charset\n");
		return false;
	}

	//black - transparent (just for charset)
	SDL_SetColorKey(charset, SDL_TRUE, 0x000000);

	return true;
}

void Game::mapColors() {
	black = SDL_MapRGB(Sample::screen->format, 0x00, 0x00, 0x00);
	green = SDL_MapRGB(Sample::screen->format, 0x00, 0xFF, 0x00);
	red = SDL_MapRGB(Sample::screen->format, 0xFF, 0x00, 0x00);
	blue = SDL_MapRGB(Sample::screen->format, 0x11, 0x11, 0xCC);
	coolBlue = SDL_MapRGB(Sample::screen->format, 0x6F, 0xA8, 0xFF);
	bgcolor = SDL_MapRGB(Sample::screen->format, 3,3,27);
}

void Game::initTime() {
	t1 = SDL_GetTicks();

	quit = false;

	worldTime = 0;
}

void Game::drawMenu() {
	int step = gameMap_->getPlayer()->getCountStep();
	DrawRectangle(Sample::screen, 67, 515, 144, 72, bgcolor, bgcolor);
	if (step > 0)
		sprintf(text, "%d", step);
	else
		sprintf(text, "x");
	if (step > 9)
		DrawString(Sample::screen, 67, 515, 72, text, charset);
	else	
		DrawString(Sample::screen, 102, 515, 72, text, charset);
	DrawRectangle(Sample::screen, 1067, 532, 160, 40, bgcolor, bgcolor);
	switch (currentMapID) {
		case 1:
			sprintf(text, "I");
			DrawString(Sample::screen, 1127, 532, 40, text, charset);
			break;
		case 2:
			sprintf(text, "II");
			DrawString(Sample::screen, 1107, 532, 40, text, charset);
			break;
		case 3:
			sprintf(text, "III");
			DrawString(Sample::screen, 1087, 532, 40, text, charset);
			break;
		case 4:
			sprintf(text, "IV");
			DrawString(Sample::screen, 1107, 532, 40, text, charset);
			break;
		case 5:
			sprintf(text, "V");
			DrawString(Sample::screen, 1127, 532, 40, text, charset);
			break;
		case 6:
			sprintf(text, "VI");
			DrawString(Sample::screen, 1107, 532, 40, text, charset);
			break;
		case 7:
			sprintf(text, "VII");
			DrawString(Sample::screen, 1087, 532, 40, text, charset);
			break;
		case 8:
			sprintf(text, "VIII");
			DrawString(Sample::screen, 1067, 532, 40, text, charset);
			break;
		case 9:
			sprintf(text, "IX");
			DrawString(Sample::screen, 1107, 532, 40, text, charset);
			break;
		case 10:
			sprintf(text, "X");
			DrawString(Sample::screen, 1127, 532, 40, text, charset);
			break;
	}
	//info text
	//rectangular background
	DrawRectangle(Sample::screen, 400, 650, SCREEN_WIDTH - 800, 65, bgcolor, bgcolor);
	//first line of text
	sprintf(text, "Elapsed time = %.1lf s", worldTime);
	DrawString(Sample::screen, Sample::screen->w / 2 - strlen(text) * 10 / 2, 670, 10, text, charset);
	//second line of text
	sprintf(text, "ESC - Menu, R - reset game");
	DrawString(Sample::screen, Sample::screen->w / 2 - strlen(text) * 10 / 2, 700, 10, text, charset);
}

void Game::drawVictoryMenu() {
	countMap += checkMap[currentMapID];
	if (countMap == MAP_COUNT) {
		loadEnding();
	}
	checkMap[currentMapID] = 0;
	DrawRectangle(Sample::screen, 400, 650, SCREEN_WIDTH - 800, 65, bgcolor, bgcolor);
	sprintf(text, "Congratulations, you solved the puzzle!");
	DrawString(Sample::screen, Sample::screen->w / 2 - strlen(text) * 10 / 2, 670, 10, text, charset);
	sprintf(text, "Time = %.1lf s, Press Enter to next level", worldTime);
	DrawString(Sample::screen, Sample::screen->w / 2 - strlen(text) * 10 / 2, 700, 10, text, charset);
}

// cleans all SDL Related things
void Game::freeSpace() {
	mus->freeMus();
	delete img;
	delete menu;
	SDL_FreeSurface(charset);
	cleanSDL();
	SDL_Quit();
}

// renders everything on screen
void Game::render() {
	//updates everything on texture
	SDL_UpdateTexture(Sample::scrtex, NULL, Sample::screen->pixels, Sample::screen->pitch);

	//connects the new texture with renderer
	SDL_RenderCopy(Sample::renderer, Sample::scrtex, NULL, NULL);
	
	//renders
	SDL_RenderPresent(Sample::renderer);
}

void Game::handleEvents() {
	InputHandler handler;
	switch (handler.handleKeyStates()) {
		case MOVE_UP:
			gameMap_->getPlayer()->movePlayer(0, -1);
			break;
		case MOVE_DOWN:
			gameMap_->getPlayer()->movePlayer(0, 1);
			break;
		case MOVE_LEFT:
			gameMap_->getPlayer()->movePlayer(-1, 0);
			break;
		case MOVE_RIGHT:
			gameMap_->getPlayer()->movePlayer(1, 0);
			break;
		case RESTART:
			initTime();
			//call a function reverting the current field
			delete gameMap_;
			img->getgPNGSurface();
			createMap();
			if (!mus->getIsPlayMusic())
				mus->continuePlayMus();
			break;
		case QUIT:
			SDL_Quit();
			break;
		case NEXT_MAP:
			if (victory) {
				delete gameMap_;
				setVictory(false);
				initTime();
				currentMapID++;
				if (currentMapID > MAP_COUNT) 
					currentMapID = 1;
				createMap();
				img->getgPNGSurface();
				drawMenu();
				gameMap_->drawMap();
				render();
			}
			break;
		case MENU:
			int selection = menu->loadMenu();
			switch (selection) {
				case 1:
					img->getgPNGSurface();
					gameMap_->drawMap();
					render();
					break;
				case 2:
					delete gameMap_;
					setVictory(false);
					initTime();
					currentMapID++;
					if (currentMapID > MAP_COUNT) 
						currentMapID = 1;
					createMap();
					img->getgPNGSurface();
					drawMenu();
					gameMap_->drawMap();
					render();
					break;
				case 3:
					if (mus->getIsPlayMusic())
						mus->stopMus();
					else
						mus->continuePlayMus();
					img->getgPNGSurface();
					gameMap_->drawMap();
					render();
					break;
				case 4:
					delete gameMap_;
					setVictory(false);
					initTime();
					gameStart();
					break;
			}
			break;
	}
}

void Game::update() {

	t2 = SDL_GetTicks();

	// here t2-t1 is the time in miliseconds since
	// the last screen was drawn
	// delta is the same time in seconds
	if (gameMap_->getPlayer()->getCountStep() < 0) {
		mus->stopMus();
		drawLose();
		initTime();
		//call a function reverting the current field
		delete gameMap_;
		img->getgPNGSurface();
		createMap();
		if (!mus->getIsPlayMusic())
			mus->continuePlayMus();
		drawMenu();
		render();
	}
	else {
		if (!victory) {
			delta = (t2 - t1)*0.001;
			// clear time difference
			t1 = t2;

			//increase world time
			worldTime += delta;

		}
		//info text
		if (victory) {
			drawVictoryMenu();
		}
		else
			drawMenu();
		gameMap_->drawMap();
		//render everything on screen
		handleEvents();

		render();
	}
}

void Game::gameStart() {
	if (menu->loadMainMenu()) {
		currentMapID = menu->getMapID();
		initTime();
		createMap();
		gameLoop();
	}
}

void Game::gameLoop() {
	img->getgPNGSurface();
	mus->playMus();
	while (!quit) {
		//move to update
		update();
	}
}

// frees all key SDL structures
void Game::cleanSDL() {
	SDL_FreeSurface(Sample::screen);
	SDL_DestroyTexture(Sample::scrtex);
	SDL_DestroyWindow(Sample::window);
	SDL_DestroyRenderer(Sample::renderer);
}

void Game::setQuit(const bool value) {
	quit = value;
}

Map* Game::getMap() {
	return gameMap_;
}

SDL_Surface* Game::getScreen() {
	return Sample::screen;
}

void Game::loadEnding() {
	mus->stop();
	mus->loadEnd();
	mus->playEnd();
	img->loadEnd();
	img->getEnd();
	render();
	SDL_Delay(30000);
	SDL_Quit();
}