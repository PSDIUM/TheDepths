#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/network.hpp"

class State
{
private:
	//Variables
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	//Functions
	State(sf::RenderWindow* window);
	virtual ~State();
	
	const bool& GetQuit() const;
	virtual void CheckForQuit();
	virtual void Quit() = 0;
	virtual void UpdateKeybinds(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;
};

