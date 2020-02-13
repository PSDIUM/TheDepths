#pragma once

#include "State.h";


class Game
{

private:

	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Clock dtClock;
	float dt;

	//Initialisation
	void InitWindow();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};

