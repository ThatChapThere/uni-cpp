#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"

Robot::Robot(std::string s): name(s)
{
	_history = new std::vector<int>;
}

Robot::~Robot()
{
// 	delete _history;
}

void Robot::whoAmI()
{
	std::cout << "class: Robot, name: " << name << std::endl;
}

void Robot::work()
{
	workUnit++;
	std::cout << "The new value of workUnit is: " << workUnit << std::endl;
	_history->push_back(workUnit);
}

void Robot::setName(std::string s)
{
	name = s;
}

void Robot::printWork()
{
	for(int workAmount: *_history)
		std::cout << workAmount << " ";
	std::cout << std::endl;
}
