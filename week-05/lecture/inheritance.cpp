#include <iostream>

using std::cout,
      std::endl;

class Base
{
public:
	Base()
	{
		cout << "base class constructor" << endl;
	}
	virtual void vtest()
	{
		cout << "base class virtual method OOO" << endl;
	}
	// it's good practice to make destructors virtual
	//
	// destructors are not like other methods, and all of them in
	// a class heirachy are called no matter what
	// when the delete keyword is used
	// starting from the destructor of the current object
	//
	// this is confusing at first, since other virtual methods are overidden
	// completely
	//
	// however, even if you think of virtual destructor in that way,
	// the delete keyword just selects a starting point and
	// make its way up the class heirachy
	// the starting point will be variable.~Destructor()
	// which if virtual, will start at the destructor
	// of the class used for initialisation, rather than the current type
	//
	// this is becuase delete is a complex process and not a simple
	// method call
	//
	// the delete keyword only cares about the position of the DESTRUCTOR
	// in the class heirachy, not the position of the POINTER TYPE
	virtual ~Base()
	{
		cout << "base class destructor" << endl;
	}
};

class Derived: public Base
{
public:
	Derived()
	{
		cout << "derived class constructor" << endl;
	}
	void vtest()
	{
		cout << "derived class virtual method XXX" << endl;
	}
	~Derived()
	{
		cout << "derived class destructor" << endl;
	}
};

class PureBase
{
public:
	PureBase() {}
	// methods, even pure methods, need parenthese
	virtual void test() = 0;
};

class ImpureBase
{
public:
	virtual void test() {};
};

class BaseThatRequiresArguments
{
private:
	int x, y;
public:
	BaseThatRequiresArguments(int a, int b): x(a), y(b) {}
	BaseThatRequiresArguments(): x(1), y(0) {}
	int getX() { return x; }
};

// there are two ways to inherit from this:
// 1. Constructor that explicity calls a parent constructor
// 2. Constructor that implicity calls a parent constructor
//     (this requires the parent to have a constructor with 0 arguments)

class DerivedCallsParentConstructor: public BaseThatRequiresArguments
{
public:
	DerivedCallsParentConstructor(int c):
		BaseThatRequiresArguments(1, 2) {}
};

class DerivedDefualtsToParentConstructor: public BaseThatRequiresArguments
{
public:
	DerivedDefualtsToParentConstructor(int j) {}
	void randomMethodLol() {}
};

class MethodOverridingTestBase
{
public:
	int add(int a, int b) { return a + b; }
};

class MethodOverridingTestDerived
{
public:
	// you can do overloading as well as overriding
	int add(int a, int b) { return a - b; }
	int add(int a, int b, int c) { return a - b + c; }
	double add(double a, double b) { return a + b; }
};

int main()
{
	// the following outputs:
	//
	// base class constructor
	// derived class constructor
	// ...
	// derived class destructor
	// base class destructor
	//
	// this ensures that there is no point where the derived class exists
	// while the base class does not
	// 
	// the derived class is temporally a subset of the base class
	//
	// this way, the derived class destructor can make calls to base
	// class methods
	// and the same logic applies to the constructor

	//Derived d1;
	//d1.vtest();
	
	cout << endl 
	     << "dynamically allocating a derived instance to a base pointer"
	     << endl << endl;
	Base *baseDynamic = new Derived();
	// this still calls the derived method since the method is virtual
	baseDynamic->vtest();
	delete baseDynamic;

	cout << endl 
	     << "statically allocating a derived instance using derived constructor"
	     << endl << endl;
	Base baseStatic = Derived();
	baseStatic.vtest();

	cout << endl 
	     << "statically allocating a derived instance using default copy constructor"
	     << endl << endl;
	Derived derivedStatic = Derived();
	Base baseStaticCopied = derivedStatic;
	baseStaticCopied.vtest();

	// the following cannot be instantiated since it contains a pure
	// method:
	// - PureBase pb;
	ImpureBase ib;
	
	DerivedCallsParentConstructor dcpc(2);
	cout << dcpc.getX() << endl;
	DerivedDefualtsToParentConstructor ddtpc(9357);
	cout << ddtpc.getX() << endl;

	cout << "--------------------------------------------------" << endl;
	return 0;
}
