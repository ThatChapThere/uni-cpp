#include <iostream>
#include <string>
#include "SocialRobot.h"

// in this file we can remove the definion of the work method
// since it is not changed.
// however, whoAmI is overidden and so must be redefined

void SocialRobot::sayHello()
{
	std::cout << "I am a social robot" << std::endl;
}

std::string SocialRobot::getMyName()
{
	return myName;
}

void SocialRobot::whoAmI()
{
	std::cout << "class:SocialRobot, name: " << name << std::endl;
}
