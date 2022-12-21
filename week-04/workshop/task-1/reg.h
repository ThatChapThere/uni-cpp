#ifndef REGISTRATION_H
#define REGISTRATION_H

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

#endif
