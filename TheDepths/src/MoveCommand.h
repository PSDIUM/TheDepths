#pragma once
#include "Command.h"

class MoveCommand : public Command
{

private:
	float dirX;
	float dirY;

public:

	MoveCommand(float dirX, float dirY);
	virtual ~MoveCommand();

	virtual void execute(const float& dt, Entity* entity);
};

