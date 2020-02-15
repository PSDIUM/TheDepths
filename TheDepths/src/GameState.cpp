#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, InputHandler* inputHandler) : State(window, inputHandler)
{

}

GameState::~GameState()
{

}

void GameState::Quit()
{
	//Handle all functions required before the state is closed
	std:: cout << "Ending GameState" << std::endl;
}

void GameState::UpdateInput(const float& dt)
{
	this->CheckForQuit();
	Command* command = this->inputHandler->handleMoveInput();
	if (command) {
		command->execute(dt, &player);
	}
}

void GameState::Update(const float& dt)
{
	this->UpdateInput(dt);
	this->player.update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	this->player.render(this->window);
}
