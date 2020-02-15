#include "InputHandler.h"
#include "MoveCommand.h"

//Public Functions

InputHandler::InputHandler()
{
	this->keyA = new MoveCommand(-1, 0);
	this->keyD = new MoveCommand(1, 0);
	this->keyW = new MoveCommand(0, -1);
	this->keyS = new MoveCommand(0, 1);
}

InputHandler::~InputHandler()
{

}

void InputHandler::handleInput()
{

}

Command* InputHandler::handleMoveInput()
{
	if (isPressed(sf::Keyboard::A)) return keyA;
	if (isPressed(sf::Keyboard::D)) return keyD;
	if (isPressed(sf::Keyboard::W)) return keyW;
	if (isPressed(sf::Keyboard::S)) return keyS;

	return NULL;
}

//Private Functions

bool InputHandler::isPressed(int key)
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key));
}


