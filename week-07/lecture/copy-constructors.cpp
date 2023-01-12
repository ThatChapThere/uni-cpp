// copy constructors are created by default when not defined
// they create a shallow copy
// !! apparently the lecture isn't quite correct
// !! the default copy constructor actuall calls the copy constructors
// !! of all member variables
// this means that all value types are copied
// and all reference types are too, but what they point to is not
// this means that it is indefinitely recursive by defualt as
// long as all objects are value types!
//
// however, for reference types, it must be defined by the program
// making liberal use of dynamic allocation

#include <iostream>

using std::cout, std::endl;

class Copyable
{
private:
	bool isOriginal;
public:
	Copyable(): isOriginal(true) {}
	void printOriginality()
	{
		cout << "This is " << (isOriginal ? "an original" : "a copy") << endl;
	}
	// copy constructors are called only on uninitilised objects
	// this includes when passed by value to a function
	// and during inline initilisation
	//
	// they are a constructor and thus return no value
	// they have the same syntax as any other constructor
	// but they just take a constant reference of the same type
	//
	// constant because mutating the object being copied would
	// be against the entire concept of copying
	//
	// and a reference to stop it from calling itself in an
	// infinite loop!
	Copyable(const Copyable &obj): isOriginal(false) {}
};
// sidenote: const works for basically everything and does what you
// would expect: prevents mutation

// this will only ever output "This is a copy"
// if the argument was a reference or pointer this would actually work
void printOriginality(Copyable instance)
{
	instance.printOriginality();
}

int main()
{
	Copyable c1;
	Copyable c2 = c1;

	Copyable c3;
	c3 = c1;

	c1.printOriginality(); // this is an original
	c2.printOriginality(); // this is a copy
	c3.printOriginality(); // this, despite being assigned to c1
						   // is considered an original since it was
						   // already declared and thus use the assignment
						   // operator and not the copy constructor
						   // this is because the copy construcor is still a 
						   // constructor and therefore can only be called
						   // when intialising a new object

	printOriginality(c1);
	printOriginality(c2);
	printOriginality(c3);
	return 0;
}
