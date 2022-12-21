#include <iostream>
#include <string>
#include "ClassChild.h"

ClassChild::ClassChild(): message("Hello!")
{
	std::cout << "ChildClass instance created" << std::endl;
}

ClassChild::~ClassChild()
{
	std::cout << "ChildClass instance deleted" << std::endl;
}

std::string ClassChild::hello()
{
	return message;
}
