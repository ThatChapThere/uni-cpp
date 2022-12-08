#include <iostream>
#include <string>
#include "ClassParent.h"

ClassParent::ClassParent()
{
	std::cout << "class instance created" << std::endl;
}

ClassParent::~ClassParent()
{
	std::cout << "class instance destroyed" << std::endl;
}
