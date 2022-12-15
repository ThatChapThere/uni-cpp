#ifndef PAPER_H
#define PAPER_H

#include "Tool.h"

class Paper: public Tool
{
public:
	Paper(int strength);
	bool fight(Tool& tool);
};

#endif
