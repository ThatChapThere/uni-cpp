#include <iostream>
#include "Registration.h"

using namespace std;

bool Registration::input()
{
	cout << "Enter the access code: ";
	cin >> code;

	bool codeCorrect = checkCode();

	setRecord(codeCorrect);
	return codeCorrect;
}

void Registration::output()
{
	cout << "attend = " << attend << endl;
}

bool Registration::checkCode()
{
	int accesscode = 123456;

	if(code == accesscode)
	{
		cout << "Registered successfully." << endl;
		return true;
	}
	return false;
}

void Registration::setRecord(bool index)
{
	attend = index ? "TRUE" : "FALSE";
}

int Registration::getCode() {return code;}
