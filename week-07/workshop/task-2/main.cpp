#include <iostream>
#include "Robot.h"
#include "SocialRobot.h"
#include "IndustrialRobot.h"
#include "AutonomousCar.h"

using std::cout,
      std::endl;

int main()
{
	Robot r2;
	{
		Robot r1("r1");
		r1.whoAmI();
		r1.work();
		r1.work();
		r1.printWork();
		cout << "assign r1 to r2..." << endl;
		r2 = r1;
		r2.setName("r2");
		r2.whoAmI();
		r2.printWork();
	}
	r2.whoAmI();
	// when we first ran the program this lead to a segfault
	// because the work vector gets deleted when r1 goes out of scope
	// in the robot destructor
	r2.printWork();
	cout << "end of example code..." << endl;
	return 0;
}
