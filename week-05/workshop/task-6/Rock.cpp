#include "Tool.h"
#include "Rock.h"

Rock::Rock(int strength)
{
	type = 'r';
	setStrength(strength);
}

bool Rock::fight(Tool& tool)
{
	// return true if win, false if loss or draw
	return tool.type == 's' ? strength * 2    > tool.strength:
	       tool.type == 'p' ? strength / 2.0f > tool.strength:
	                          strength        > tool.strength;
}
