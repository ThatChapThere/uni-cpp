//#ifndef ATONOMOUSCAR_H
//#define ATONOMOUSCAR_H

#include <string>
#include "Robot.h"

enum class direction {north, east, south, west};

class AutonomousCar: public Robot
{
private:
	enum coordinate {x=0, y=1};
	int coordinates[2] = {0, 0};
public:
	AutonomousCar(std::string n="default car name"): Robot(n) {}
	void whoAmI();
	void drive(unsigned distance, direction orientation);
	void work();
};

//#endif
