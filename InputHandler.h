#pragma once
#include "Function.h"

enum Event {
	NEXT_MAP,
	QUIT,
	NO_EVENT,
	MOVE_UP,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_DOWN,
	RESTART,
	MENU
};

class InputHandler {
public:
	InputHandler();
	~InputHandler();
	//handles all key events
	Event handleKeyStates();
};