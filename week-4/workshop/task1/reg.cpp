#include <iostream>
#include "reg.h"

using namespace std;

// inpt
//Uses iostream:
bool Registration::input()
{
	// print a message asking the user to input a code
	cout << "Enter the access code: ";
	// put the code that the user enters into the private code member variable
	cin >> code;
	// check the code that the user just entered
	// -- checkCode is called here in the input() method and its output is used to set the
	// -- value of the record
	if (checkCode())
	{
		// set the record to true if the code was entered correctly
		setRecord(true);
		return true;
	}
	else
	{
		// set the record to false if the code was entered incorrectly
		setRecord(false);
		return false;
	}
}

void Registration::output()
{
	// print whether or not attendance has been registered to the user
	cout << "attend = " << attend << endl;
}

void Registration::setRecord(bool index)
{
	// check the value of the parameter
	if (index)
		// if it was true set the attendance accordingly
		attend = "TRUE";
	else
		// if it was false set the attendance accordingly
		attend = "False";
}

bool Registration::checkCode()
{
	// this sets the value of the correct access code
	int accesscode = 123456;
	// check that the code the user entered is the correct code
	if (code == accesscode)
	{
		// print a message to the user that registration was successful
		cout << "Register successfully.\n";
		// return the fact that registration was a success so that this information
		// can be used by the method that called checkCode()
		return true;
	}
	else
	{
		// return the fact that registration was a failure so that this information
		// can be used by the method that called checkCode()
		return false;
	}
}

int Registration::getCode()
{
	// return the value of the code member variable
	return code;
}
