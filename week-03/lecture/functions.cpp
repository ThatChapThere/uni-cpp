#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void function_to_point_to(int argument)
{
	int pointless = 38;
}

int main()
{
	// a couple of things about the syntax here:
	// first of all you have to put the name of 
	// the pointer in quotes so the compiler doesn't think
	// you're trying to declare a new function
	//
	// secondly you have to put the argument list after
	// think of it as part of the type definition 
	void (*function_pointer)(int argument) = function_to_point_to;
	return 0;
}
