#include <iostream>
// if a library is used for method arguments then
// it will already be included in the header
//#include <string>
#include "A.h"

A::~A()
{
	delete name;
}

void A::setName(const std::string &n)
{
	*name = n;
}

void A::printName()
{
	using std::cout,
	      std::endl;
	cout << *name << endl;
}
