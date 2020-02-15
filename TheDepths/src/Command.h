#pragma once

#include "Entity.h"

class Command
{

private:

public:
	
	//Functions
	virtual ~Command();
	virtual void execute(const float& dt, Entity* entity) = 0;
};

