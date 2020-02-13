#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Vector>

#include "SFML/System.hpp";
#include "SFML/Window.hpp";
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp";
#include "SFML/network.hpp";



class State
{
private:
	//Variables
	std::vector<sf::Texture> textures;

public:
	//Functions
	State();
	virtual ~State();

	virtual void Update() = 0;
	virtual void Render() = 0;
};

