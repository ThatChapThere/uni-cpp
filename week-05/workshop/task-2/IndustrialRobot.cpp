#include <iostream>
#include "IndustrialRobot.h"

// work method removed

void IndustrialRobot::whoAmI()
{
	std::cout << "class: IndustrialRobot, name: " << name << std::endl;
}

void IndustrialRobot::workHarder()
{
	std::cout << "Previous value of workUnit: " << workUnit;
	workUnit += 2;
	std::cout << ", new value of workUnit: " << workUnit << std::endl;
}
