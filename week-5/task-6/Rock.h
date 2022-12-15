#ifndef ROCK_H
#define ROCK_H

#include "Tool.h"

class Rock: public Tool
{
public:
	Rock(int strength);
	bool fight(Tool& tool);
};

#endif
