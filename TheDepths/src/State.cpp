#include "State.h"

State::State(sf::RenderWindow* window, InputHandler* inputHandler) 
{
	this->window = window;
	this->inputHandler = inputHandler;
	this->quit = false;
}

State::~State() 
{

}

const bool& State::GetQuit() const
{
	return this->quit;
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}
