#pragma once

#include "State.h"

class GameState :
	public State
{
private:
	Entity player;

public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	//Functions
	void Quit();
	void UpdateKeybinds(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

