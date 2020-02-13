#include "Game.h"

//Static Functions

//Initialiser Functions

void Game::InitWindow()
{
    //Create the inital window of the game. Use file to load window settings.
	this->window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

//Constructors/Destructors


Game::Game()
{
    //Call initialising functions
    this->InitWindow();
}

Game::~Game()
{
	delete this->window;
}

//Functions

void Game::UpdateDt()
{
    //Updates the detlaTime variable with the amount of time it takes to update a single frame
    this->dt = dtClock.restart().asSeconds();

    system("cls");

    std::string deltaTime = "Delta Time: " + std::to_string(this->dt);
    std::cout << deltaTime << std::endl;
}

void Game::UpdateSFMLEvents()
{
    //Update engine events

    //Handles poll event from window
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::Update()
{
    this->UpdateSFMLEvents();
}

void Game::Render()
{
    this->window->clear();

    // Render items

    this->window->display();
}

void Game::Run()
{
	while (this->window->isOpen()) {
        this->UpdateDt();
		this->Update();
		this->Render();
	}
}
