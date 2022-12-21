#include <iostream>
#include "AutonomousCar.h"

void AutonomousCar::whoAmI()
{
	std::cout << "class: AutonomousCar, name: " << name << std::endl;
}

void AutonomousCar::drive(unsigned distance, direction orientation)
{
	std::cout << "Previous position: x: " << coordinates[x]
	          << " y: " << coordinates[y] << std::endl
	          << "Movement: " << distance << " units ";

	switch(orientation)
	{
		case direction::north:
			std::cout << "North";
			coordinates[y] -= distance;
			break;
		case direction::east:
			std::cout << "East";
			coordinates[x] += distance;
			break;
		case direction::south:
			std::cout << "South";
			coordinates[y] += distance;
			break;
		case direction::west:
			std::cout << "West";
			coordinates[x] -= distance;
			break;
	}
	std::cout << std::endl;
	std::cout << "New position: x: " << coordinates[x]
	          << " y: " << coordinates[y] << std::endl;
}

void AutonomousCar::work()
{
	std::cout << "Dammit Jim, I'm a car not a robot!" << std::endl;
}
