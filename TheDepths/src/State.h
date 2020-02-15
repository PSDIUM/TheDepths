#pragma once

#include "Entity.h"
#include "InputHandler.h"

class State
{
private:

protected:
	//Variables
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	InputHandler* inputHandler;
	bool quit;

public:
	//Functions
	State(sf::RenderWindow* window, InputHandler* inputHandler);
	virtual ~State();
	
	const bool& GetQuit() const;
	virtual void CheckForQuit();
	virtual void Quit() = 0;
	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
};

