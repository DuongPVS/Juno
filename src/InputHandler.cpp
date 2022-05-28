#include "InputHandler.h"

InputHandler::InputHandler() {
}

InputHandler::~InputHandler() {

}

Event InputHandler::handleKeyStates() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			return QUIT;
		else if (event.type == SDL_KEYDOWN) 
			switch (event.key.keysym.sym) {
				case SDLK_UP:
					return MOVE_UP;
				case SDLK_DOWN:
					return MOVE_DOWN;
				case SDLK_LEFT:
					return MOVE_LEFT;
				case SDLK_RIGHT:
					return MOVE_RIGHT;
				case SDLK_w:
					return MOVE_UP;
				case SDLK_s:
					return MOVE_DOWN;
				case SDLK_a:
					return MOVE_LEFT;
				case SDLK_d:
					return MOVE_RIGHT;
				case SDLK_r:
					return RESTART;
				case SDLK_ESCAPE:
					return MENU;
				case SDLK_RETURN:
					return NEXT_MAP;
			}
	}
	return NO_EVENT;
}
