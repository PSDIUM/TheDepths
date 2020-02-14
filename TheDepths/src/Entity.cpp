#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->movementSpeed = 100.0f;
}

Entity::~Entity()
{

}

void Entity::move(const float& dt, const float dirX, const float dirY) 
{
	shape.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(dt, -1,0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(dt, 1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->move(dt, 0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->move(dt, 0, 1);
	}
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
