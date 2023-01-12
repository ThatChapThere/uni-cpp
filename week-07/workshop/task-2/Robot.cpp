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
	// this line is commented out becuse it causes a segfault when you
	// assign another variable to the value as in main.cpp
	// I think you need to override the assignment operator to make it work
	// but, given that this task exists before that lecture
	// I wonder if there's another way
	// There isn't:
	// - the fact of deallocation is itself data
	// - this data must be stored on the heap so that it outlives r1
	// - this cannot be gaurunteed to be deallocated
	// - therefore either a segfault or a memory leak is inevitable
	// without overriding the assignment operator
 	delete _history;
 	// this was a failed attempt -  this only changes the pointer in r1
 	// and not r2
	_history = NULL;
}

std::vector<int> *Robot::getHistory()
{
	if(_history == NULL) _history = new std::vector<int>;	
	return _history;
}

void Robot::whoAmI()
{
	std::cout << "class: Robot, name: " << name << std::endl;
}

void Robot::work()
{
	workUnit++;
	std::cout << "The new value of workUnit is: " << workUnit << std::endl;
	getHistory()->push_back(workUnit);
}

void Robot::setName(std::string s)
{
	name = s;
}

void Robot::printWork()
{
	for(int &workAmount: *getHistory()) std::cout << workAmount << " ";
	std::cout << std::endl;
}
