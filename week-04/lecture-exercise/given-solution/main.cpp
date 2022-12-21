#include <iostream>
#include "Registration.h"

using namespace std;

int main()
{
	Registration myCode;

	cout << "Registration:" << endl;

	if(myCode.input())
	{
		cout << "The input code was " << myCode.getCode() << endl;
		cout << "The system has been updated with ";
		myCode.output();
	}else{
		cout << "Your input code " << myCode.getCode() << " doesn't match the access code" << endl;
		cout << "Registration unsuccessful." << endl;
	}
	return 0;
}
