#pragma once

#include "GameState.h"
#include "InputHandler.h"

class Game
{

private:

	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	InputHandler inputHandler;

	//Initialisation
	void InitWindow();
	void InitStates();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void OnEndApplication();

	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};

