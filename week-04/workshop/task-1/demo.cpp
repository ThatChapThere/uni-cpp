#include <iostream>
#include "reg.h"

using namespace std;

int main()
{
	// create a new instace of the registration class
	Registration myCode;
	// print a message to the user letting them know that this is for registration
	cout << "Registration:\n";
	// check that the user input is correct
	// -- the input() method which is called here calls the getCode() method
	// -- the input() method actually returns the value returned by getCode()
	// -- so the value of getCode() is here used to output the correct message to the user
	if (myCode.input())
	{
		// print a message with the input code informing the user that they entered it correctly
		cout << "The input code is " << myCode.getCode() << "\n";
		cout << "The system has been updated with ";
		// print whether or not attendance has been registered
		myCode.output();
	}
	else
	{
		// print a message with the given input code informing the user that it is incorrect
		cout << "Your input code " << myCode.getCode() << " doesn't match the access code\n";
		cout << "Register unsuccessfully. \n";
	}
	return 0;
}
