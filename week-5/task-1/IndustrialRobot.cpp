#include <iostream>
#include "IndustrialRobot.h"

void IndustrialRobot::whoAmI()
{
	std::cout << "class: IndustrialRobot, name: " << name << std::endl;
}

void IndustrialRobot::work()
{
	workUnit++;
	std::cout << "The new value of workUnit is: " << workUnit << std::endl;
}

void IndustrialRobot::workHarder()
{
	std::cout << "Previous value of workUnit: " << workUnit;
	workUnit += 2;
	std::cout << ", new value of workUnit: " << workUnit << std::endl;
}
