#ifndef INDUSTRIALROBOT_H
#define INDUSTRIALROBOT_H

#include <string>

class IndustrialRobot
{
private:
	std::string name;
	int workUnit;
public:
	IndustrialRobot(std::string n="default industrial robot name"):
		name(n) {}
	void whoAmI();
	void work();
	void workHarder();
};

#endif
