#include "Tool.h"
#include "Scissors.h"

Scissors::Scissors(int strength)
{
	type = 's';
	setStrength(strength);
}

bool Scissors::fight(Tool& tool)
{
	// return true if win, false if loss or draw
	return tool.type == 'p' ? strength * 2    > tool.strength:
	       tool.type == 'r' ? strength / 2.0f > tool.strength:
	                          strength        > tool.strength;
}
