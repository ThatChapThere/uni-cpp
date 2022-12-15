#include "Tool.h"
#include "Paper.h"

Paper::Paper(int strength)
{
	type = 'p';
	setStrength(strength);
}
 
bool Paper::fight(Tool& tool)
{
	// return true if win, false if loss or draw
	return tool.type == 'r' ? strength * 2    > tool.strength:
	       tool.type == 's' ? strength / 2.0f > tool.strength:
	                          strength        > tool.strength;
}
