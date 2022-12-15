#include <iostream>

using namespace std;

// overloading functions is when there is more than one
// function with the same name AND RETURN TYPE but a different set of arguments
// remember the part about the return types

// you can automatically overload functions by giving them default values
// this only applies to the last arguments
// ie. you cannot have a non defaulted value after a defaulted value
// this makes sense since a limited list of arguments
// would be otherwise ambiguous
int func1(int a, int b=10)
{
	return a * b;
}

// of course you could also do the same thing with two separate functions
int func2(int a, int b)
{
	return a * b;
}

int func2(int a)
{
	return a * 10;
}

// the following will not compile:
// float func1(int a, int b){ return 0.5; }  
// however a different return type with the same name is perfectly valid
// as long as the arguments are different
float func1(){ return 0.5; }  

// there's actually a bit of weird nuance here
// you can have two functions which take in a float and int argument
// you need to use 1.1f and not just t1.1 in some cases
int func3(int a)
{
	cout << "int argument" << endl;
	return a;
}

int func3(float a)
{
	cout << "float argument" << endl;
	return a;
}

// obviously constructors can be overloaded just like anything else
// maybe make a file messing with this too though
// EDIT: no point, it's trivial
// there was a weird thing that looked like Robot(string n) : name {n}{...
// figure out what the fuck this is
// EDIT: it's only initialisation notation, no need to get scared
//       just typical C++ bullshit, syntax that looks confusing similar to
//       other syntax
// do the last week first though in case it's covered
// EDIT: it was

// there's a distinction to be made between overloading and overriding
// this is in that overriding is specific to class heirachies
// and have the same name and argument set and completely overwrite
// the method

// there's a bunch of constructor stuff in the lecture
// maybe make a separate file for that since this one is getting rather
// big already
// one thing was about how all defualt 
// EDIT: it was just some ambiguity that can happen, it was already
//       covered the the last lecture

int main()
{
	cout << "func1(3) = " << func1(3) << endl;
	cout << "func1(5, 3) = " << func1(5, 3) << endl;
	func3(1);
	// this causes a compiler error since it doesn't know whether to
	// cast to float or double
	// - func3(1.1);
	func3(1.1f);
	return 0;
}
