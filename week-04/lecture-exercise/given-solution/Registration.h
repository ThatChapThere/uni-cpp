#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>

class Registration
{
	public:
		// get a code from the user and validate it
		bool input();
		// display the state to the user
		void output();
		// update the value of attend
		void setRecord(bool index);
		// return the code the user inputted
		int getCode();
	private:
		// check that the input matches the access code
		bool checkCode();
		int code;
		std::string attend;
};

#endif
