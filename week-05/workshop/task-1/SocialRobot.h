#ifndef SOCIALROBOT_H
#define SOCIALROBOT_H

#include <string>

class SocialRobot
{
private:
	std::string name;
	int workUnit;
	std::string myName;
public:
	SocialRobot(std::string n="default social robot name"):
		name(n), myName(n) {}
	void whoAmI();
	void work();
	void sayHello();
	std::string getMyName();
};

#endif
