#include <iostream>
#include <string>
#include "ClassParentParent.h"

ClassParentParent::ClassParentParent()
{
	std::cout << "class instance created" << std::endl;
}

ClassParentParent::~ClassParentParent()
{
	std::cout << "class instance destroyed" << std::endl;
}
