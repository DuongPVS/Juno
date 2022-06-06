#include "Game.h"

// main
int main(int argc, char **argv) {
	Game* game = new Game();
	if (!game->initialize()) {
		printf("Cannot initialize!");
		return 1;
	}
	game->gameStart();

	game->freeSpace();
	return 0;
}
