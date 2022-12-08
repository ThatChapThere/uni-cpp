#ifndef SOCIALROBOT_H
#define SOCIALROBOT_H

#include <string>
#include "Robot.h"

class SocialRobot: public Robot
{
private:
	// here we don't have to declare properties that are already
	// properties of the parent class
	std::string myName;
public:
	// Here instead of setting the value of name directly we
	// call the parent constructor
	SocialRobot(std::string n="default social robot name"):
		Robot(n), myName(n) {}
	// while whoAmI is defined for the parent class,
	// it is overidden.
	// overriding functions must be done explicitly in the class
	// definition of a child class
	// we cannot just put SocialRobot::whoAmI in SocialRobot.cpp
	// without the line below
	void whoAmI();
	void sayHello();
	std::string getMyName();
	// however, we don't need to declare the work method as
	// it is not overridden
};

#endif
