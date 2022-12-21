#ifndef INDUSTRIALROBOT_H
#define INDUSTRIALROBOT_H

#include <string>
#include "Robot.h"

class IndustrialRobot: public Robot
{
// it was actually essential to remove the member declarations here
// since a class can actually have members of the same name as those
// in the parent class
// this leads to confusing behavior
// in this case the parent class defines work()
// and this class defines workHarder()
// but these two methods ended up mutating different
// workUnit properties
public:
	IndustrialRobot(std::string n="default industrial robot name"):
		Robot(n) {}
	// rationalisation found in SocialRobot.h for changes made here
	void whoAmI();
	void workHarder();
};

#endif
