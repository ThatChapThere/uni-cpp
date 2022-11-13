#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main()
{
	// you can declare null pointers like so
	int *point1 = nullptr;
	int *point2 = 0;

	// there's a bit of nuance to pointers in C++
	// there's a new keyword which can make an entirely new pointer
	int *p1, *p2;
	p1 = new int;
	*p1 = 42;
	p2 = p1; // and they now point to the same memory location
	
	// these are of course the same
	cout << *p1 << ", " << *p2 << endl;
	
	*p2 = 53;
	// these are of course again the same
	cout << *p1 << ", " << *p2 << endl;

	p1 = new int;
	*p1 = 88;
	
	// these are not the same!!
	// since p1 has a brand spanking new memory location
	cout << *p1 << ", " << *p2 << endl;

	// references
	// they are strange creatures
	// references are like pointers except not
	// they cannot be reassigned
	// once they refer to an object, they always refer to that object
	// they cannot be null
	// they cannot just be declared
	// they must be set to refer to an object the moment they are initialised
	int number = 3;
	int &reference = number;
	// confusingly this is just as if you're copying the value
	// and it doesn't need to be dereferenced
	// int &reference; would be an error.
	
	// let me just test something...
	int index;
	// std::cin >> index;
	index = 0;

	int arr[] = {1, 2, 4, 5};

	int &array_item_reference = arr[index];

	std::cout << array_item_reference << std::endl;
	// yeah, that works
	// so you can clearly set a reference on the fly
	// i guess they'd be pretty pointless otherwise
	// you just can't reset them on the fly
	// 
	char cc[2] = {'a','d'};
	char* pl = cc;
	cout << " cc[1] = " << *pl << endl;
	cout <<" cc[2] = " << *++pl << endl;

	// generally speaking you want to use pointers when you want
	// to end up referring to different things at different times
	// and references when you don't
}
