#include "MoveCommand.h"

MoveCommand::MoveCommand(float dirX, float dirY) 
{
	this->dirX = dirX;
	this->dirY = dirY;
}

MoveCommand::~MoveCommand()
{

}

void MoveCommand::execute(const float& dt, Entity* entity)
{
	entity->move(dt, dirX, dirY);
}
