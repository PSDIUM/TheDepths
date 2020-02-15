#pragma once

#include "Command.h"

class InputHandler
{

private:
	//Variables
	Command* keyA;
	Command* keyD;
	Command* keyW;
	Command* keyS;

	//Functions
	bool isPressed(int key);

public:

	//Functions
	InputHandler();
	virtual ~InputHandler();

	void handleInput();
	Command* handleMoveInput();
	
};

