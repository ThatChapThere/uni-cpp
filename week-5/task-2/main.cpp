#include <iostream>
#include "Robot.h"
#include "SocialRobot.h"
#include "IndustrialRobot.h"

int main()
{
	Robot r1;
	Robot r2("Robot 2");
	SocialRobot s1;
	SocialRobot s2("Social Robot 2");
	IndustrialRobot i1;
	IndustrialRobot i2("Industrial Robot 2");
	// Robot instances
	r1.whoAmI();
	r2.whoAmI();
	r2.work();
	// SocialRobot instances
	s1.whoAmI();
	s2.whoAmI();
	s2.work();
	s2.sayHello();
	std::cout << s2.getMyName() << std::endl;
	// IndustrialRobot instances
	i1.whoAmI();
	i2.whoAmI();
	i2.work();
	i2.workHarder();
	return 0;
}
