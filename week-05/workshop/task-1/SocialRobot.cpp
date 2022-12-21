#include <iostream>
#include <string>
#include "SocialRobot.h"

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

void SocialRobot::work()
{
	workUnit++;
	std::cout << "The new value of workUnit is: " << workUnit << std::endl;
}
