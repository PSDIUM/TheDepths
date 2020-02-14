#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
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

void GameState::UpdateKeybinds(const float& dt)
{
	this->CheckForQuit();
}

void GameState::Update(const float& dt)
{
	this->UpdateKeybinds(dt);
	this->player.update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	this->player.render(this->window);
}
