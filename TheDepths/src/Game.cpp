#include "Game.h"

//Static Functions

//Initialiser Functions

void Game::InitWindow()
{
    //Create the inital window of the game. Use file to load window settings.
    std::ifstream ifs("config/window.ini");

    std::string title = "None";
    sf::VideoMode windowBounds(800,600);
    unsigned framerateLimit = 120;
    bool verticalSyncEnabled = 0;

    if (ifs.is_open()) 
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
    } 
    else
    {
        std::cout << "There was an error opening the window config file" << std::endl;
    }

    ifs.close();

	this->window = new sf::RenderWindow(windowBounds, title);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled (verticalSyncEnabled);
}

void Game::InitStates()
{
    this->states.push(new GameState(this->window, &this->inputHandler));
}

//Constructors/Destructors

Game::Game()
{
    //Call initialising functions
    std::cout << "Game starting" << std::endl;

    this->InitWindow();
    this->InitStates();
}

Game::~Game()
{
   

	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
        
}

//Functions

void Game::UpdateDt()
{
    //Updates the detlaTime variable with the amount of time it takes to update a single frame
    this->dt = dtClock.restart().asSeconds();

    //system("cls");

    //std::string deltaTime = "Delta Time: " + std::to_string(this->dt);
    //std::cout << deltaTime << std::endl;
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

    //Application Running
    if (!this->states.empty()) {
        this->states.top()->Update(this->dt);

        if (this->states.top()->GetQuit()) {
            this->states.top()->Quit();
            delete this->states.top();
            this->states.pop();
        }
    }
    //Application End
    else
    {
        this->OnEndApplication();
        this->window->close();
    }
        
}

void Game::Render()
{
    this->window->clear();

    // Render items
    if (!this->states.empty()) 
        this->states.top()->Render();

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

void Game::OnEndApplication()
{
    std::cout << "Game closing" << std::endl;
}

