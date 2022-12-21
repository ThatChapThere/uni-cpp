#include <iostream>
// up here in the preprocessor area you would
// also include any other files
// you can use multiple files in C++
// There are three types of file in this system:
// Interface file:
//     also called a header file
//     contains class definitions
//     should have comments documenting what the functions actually do
//     looks like:
//     ==ClassName.h==
// Implementation file:
//     contains class implementation
//     uses :: to define class methods and constructors
//     must #include "ClassName.h"
//     looks like:
//     ==ClassName.cpp==
// Application file:
//     contains higher level functions in some cases
//     contains declarations of program constants
//     has lots of include directives
//     looks like:
//     ==main.cpp==
using namespace std;

// classes in C++ are almost identical to structs
// since structs can also contain functions
// there is only one difference between the two:
// struct members are public by default,
// making structs backwards compatible with C
// while class members are private by default
// 
// however, structs should only really be used for pure data
// in most cases
class ExampleClass
{
	// it's considered good practice to make all class members
	// private along with all helper functions 
	// this ensures the kind of encapsulation you need in most cases
	// it's probably also a good idea to make getter and setter
	// methods
	// C# style properties don't exist in C++
	// so you have to do this with getMember() style methods
	// (or fancy stuff with generics, or god forbid macros)
private:
	int exampleMember1;
	int exampleMember2;

public:
	void exampleMethod1()
	{
		exampleMember1 = 1;
	}
	void exampleMethod2();
	// A constructor is the function that is called when a 
	// class is initialised
	// it can be overloaded like any other function
	// and like in most languages you don't specify a return type
	ExampleClass()
	{
		cout << "An instance of ExampleClass was initialised" << endl;
	}
}; // again, classes need a semicolon after being declared!

// methods can also be defined outside of a class definition
// using scope resolution ::
// in fact, the lecture mentions this and not the "normal" way
// there's no benefit to this if you're only working with one file
// but if you're using header files you need this
//
// REMEMBER: just because a function is declared inside a class
// doesn't mean you don't still need to specify the return type here
void ExampleClass::exampleMethod2()
{
	exampleMember2 = 2;
}

int main()
{
	ExampleClass exampleInstance;
	// here we can see the distinction between the usage of
	// the member operator . and the scope resolution
	// operator ::
	// the member operator is used on instances of a class
	// and the scope resolution operator is used the the
	// class itself
	// in this example:
	//     ExampleClass::member
	//     exampleInstance.member
	exampleInstance.exampleMethod1();
	exampleInstance.exampleMethod2();
	
	return 0;
}
