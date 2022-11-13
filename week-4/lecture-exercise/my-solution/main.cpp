// === write a small program that mimics a registration process: ===
// The user is required to input a access code, and the program will
// validate the input code, if the input code is correct (matches to the
// system provided code), will return truth for registration while
// update the log (e.g. property attend = 1), otherwise shows “wrong
// code” with attend = 0.
#include <iostream>

using namespace std;

// there are a few things about this solution which are bad practice
// - the registration system can be put into a single
// class and probably should be, since it does one thing
// - the main function has more program logic in it that is really
// needed, and does logic which can and should be absracted away
// not in the sense of containing if statments
// but in the sense of containing a cin usage
// IO is a low level operation and
// the main function should only really do
// the highest level operations
class Log
{
private:
	int value = 0;

public:
	// in the given solution there are no one line methods
	// except for getters which have to be
	// this is because functions that only execute one
	// line of code are in most cases pointless
	// especially void methods
	// in this particular case it seems necessary since
	// we have to set a private member variable
	// but that's a sign that this class does too little
	void registerSuccessfully()
	{
		value = 1;
	}
	void registerFailure()
	{
		cout << "wrong code";
	}
	int getRegistryStatus()
	{
		return value;
	}
};

class System
{
private:
	string accesscode = "091251";

public:
	bool testCode(string attempt)
	{
		return accesscode == attempt;
	}
};

int main()
{
	System registrationSystem;
	Log log;

	string userInput;
	cout << "Enter the access code: ";
	cin >> userInput;

	if(registrationSystem.testCode(userInput))
		log.registerSuccessfully();
	else
		log.registerFailure();

	if(log.getRegistryStatus())
		cout << "registered successfully";

	return 0;
}
