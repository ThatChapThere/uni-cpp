#ifndef SCISSORS_H
#define SCISSORS_H

#include "Tool.h"

class Scissors: public Tool
{
public:
	Scissors(int strength);
	bool fight(Tool& tool);
};

#endif
