#include <iostream>

using namespace std;

// unlike in C structs don't need to be typedefed
// this makes things a bit easier
struct intAndChar{
	int i;
	char c;
}; // don't forget the semicolon after a struct definition!

// structs can be passed by value or by reference
void incReference(intAndChar &inc)
{
	inc.i = 0;
}

void incValue(intAndChar inc)
{
	inc.i = 0;
}

int main()
{
	// you can just use the struct name as a type
	// unlike in C you don't need to use the struct keyword
	intAndChar instanceOfStruct;
	// access the members of a struct using dots
	instanceOfStruct.i = 10;
	instanceOfStruct.c = 'l';

	cout << instanceOfStruct.i << instanceOfStruct.c << endl;

	incValue(instanceOfStruct);
	cout << "after passing the struct by value, the value of "
	     << "instanceOfStruct.i is still " 
	     << instanceOfStruct.i << endl;  

	incReference(instanceOfStruct);
	cout << "after passing the struct by reference, the value of "
	     << "instanceOfStruct.i is now " 
	     << instanceOfStruct.i << endl;  

	// you can initialise structs like arrays
	// this does not require you to specify which members
	// you are setting
	// since they are set in order of declaration
	// for example:
	intAndChar arrayInitialised = {25, 'f'};
	cout << "with array initialisation used on a struct, the value "
	     << "of the .i property is " << arrayInitialised.i
	     << " and the value "
	     << "of the .c property is " << arrayInitialised.c << endl;
	// if the initialiser has too many members there is a
	// compilation error
	// if the initialiser has too few members the remaining ones
	// use their default initialisers
}
