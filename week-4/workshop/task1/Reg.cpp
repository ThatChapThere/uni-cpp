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
	Registration myCode;
	cout << "Registration:\n";
	if (myCode.input())
	{
		cout << "The input code is " << myCode.getCode() << "\n";
		cout << "The system has been updated with ";
		myCode.output();
	}
	else
	{
		cout << "Your input code " << myCode.getCode() << " doesn't match the access code\n";
		cout << "Register unsuccessfully. \n";
	}
	return 0;
}

//Uses iostream:
bool Registration::input()
{
	cout << "Enter the access code: ";
	cin >> code;
	if (checkCode())
	{
		setRecord(true);
		return true;
	}
	else
	{
		setRecord(false);
		return false;
	}
}

void Registration::output()
{
	cout << "attend = " << attend << endl;
}

void Registration::setRecord(bool index)
{
	if (index)
		attend = "TRUE";
	else
		attend = "False";
}

bool Registration::checkCode()
{
	int accesscode = 123456;
	if (code == accesscode)
	{
		cout << "Register successfully.\n";
		return true;
	}
	else
	{
		return false;
	}
}

int Registration::getCode()
{
	return code;
}
