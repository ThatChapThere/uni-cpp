#include <iostream>
#include "Robot.h"

void Robot::whoAmI()
{
	std::cout << "class: Robot, name: " << name << std::endl;
}

void Robot::work()
{
	workUnit++;
	std::cout << "The new value of workUnit is: " << workUnit << std::endl;
}
