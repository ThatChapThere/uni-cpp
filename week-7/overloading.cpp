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
int func3()
{
	return a;
}

// obviously constructors can be overloaded just like anything else
// maybe make a file messing with this too though
// there was a weird thing that looked like Robot(string n) : name {n}{...
// figure out what the fuck this is
// do the last week first though in case it's covered

// there's a distinction to be made between overloading and overriding
// this is in that overriding is specific to class heirachies
// and have the same name and argument set and completely overwrite
// the method

// there's a bunch of constructor stuff in the lecture
// maybe make a separate file for that since this one is getting rather
// big already
// one thing was about how all defualt 

int main()
{
	cout << "func1(3) = " << func1(3) << endl;
	cout << "func1(5, 3) = " << func1(5, 3) << endl;
	return 0;
}
