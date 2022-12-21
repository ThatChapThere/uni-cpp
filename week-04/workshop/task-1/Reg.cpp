#include <iostream>
using namespace std;

class Registration
{
public:
	bool input();
	void output();
	void setRecord(bool index);
	int getCode();
	//Returns the input code
private:
	bool checkCode(); //to check the input matches the access code
	int code;
	string attend;
};

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
