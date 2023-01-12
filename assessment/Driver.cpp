/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <functional>
#include <map>
#include <string>
// <my code> (this might be another windows thing, check before submission)
// contains the strcpy_s function
#include <cstring>
// </my code>

using namespace std;

int main()
{
	vector <Shape*> shapes;
	vector <string> parameters;
	string userCommand;
	int x, y, h, w, e, r, index;
	float scaleX, scaleY;

	// set a series of numbers (of any numerical type) from [parameters]
	// returns <true> on success and <false> on failure
	//
	// making this a lambda instead of a standalone function saves us from
	// having to pass [parameters] as an argument
	// "[&]" means that we pass in all variables on the stack for [main]
	// by reference
	auto setValuesFromParameters = 
	[&]<typename T>(vector<T*> values, const int &startIndex=1)->bool
	{
		if(parameters.size() - startIndex < values.size())
		{
			cout << "Too few arguments supplied for " << parameters[0] 
			     << " command" << endl;
			return false;
		}
		for(int i = 0; i < values.size(); i++)
		{
			string &parameter = parameters[i + startIndex];
			// here we can use the [stof] function for floats and ints
			// since [stof] will make a valid {float} from a {string}  without
			// a decimal point like "12", and it is automatically cast back to
			// {int} if neccesary
			try { *values[i] = stof(parameter); }
			catch(exception &e)
			{
				cout << parameter << " is not a number" << endl;
			}
		}
		return true;
	};

	// test if [index] is a valid index of [shapes]
	// returns <true> on success and <false> on failure
	//
	// this is 1-indexed, not 0-indexed
	auto validateIndex = [&]()->bool
	{
		if(index < 1 || shapes.size() < index)
		{
			cout << "there is no shape " << index << endl;
			return false;
		}
		return true;
	};

	// maps each user command to a corresponding function
	map<string, function<void()>> userCommands
	{
		{"addR", [&]()
		{
			// set all of the needed values from the user input
			// and return before creating a new Rectangle on failure
			if(!setValuesFromParameters(
				vector<int*> {&x, &y, &h, &w}
			)) return;
			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			cout << r;		
		}},

		{"addS", [&]()
		{
			// return early on failure
			if(!setValuesFromParameters(
				vector<int*> {&x, &y, &e}
			)) return;
			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s;
		}},

		{"addC", [&]()
		{
			// return early on failure
			if(!setValuesFromParameters(
				vector<int*> {&x, &y, &r}
			)) return;
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c;
		}},

		// scaling is isotropic in the case of circle or a square
		// and will just scale by the minimum scale factor
		{"scale", [&]()
		{
			if(!(
				setValuesFromParameters(vector<int*>   {&index}) &&
				setValuesFromParameters(vector<float*> {&scaleX, &scaleY}, 2)
			)) return;
			// make sure shape [index] exists
			if(!validateIndex()) return;
			auto shape = shapes[index - 1];
			// dynamic_cast is a runtime cast
			// if we tried to use static_cast it would cause a compiler error
			// since Shape does not inherit from Movable and you can only
			// statically cast to a parent class
			// C style casting compiles and works in this specific case,
			// but it is not good practice since dynamic_cast is memory safe
			// and returns a nullptr when the cast is not valid
			// ie. if shapes contains a class that inherits from Shape and
			// not Movable
			Movable *movableShape = dynamic_cast<Movable*>(shape);
			movableShape->scale(scaleX, scaleY);
			cout << shape;
		}},

		{"move", [&]()
		{
			// don't move a shape if the user inputs an invalid command
			if(!setValuesFromParameters(
				vector<int*> {&index, &x, &y}
			)) return;
			// make sure shape [index] exists
			if(!validateIndex()) return;
			auto shape = shapes[index - 1];
			// explained above
			Movable *movableShape  = dynamic_cast<Movable*>(shape);
			movableShape->move(x, y);
			cout << shape;
		}},

		// print out all of the shape objects
		{"display", [&]()
		{
			for(const auto &shape: shapes) cout << shape << endl << endl;
		}},

		// remove all of the shape objects and empty [shapes]
		{"clear", [&]()
		{
			for(const auto &shape: shapes) delete shape;
			shapes = {};
		}},

		// remove a specific shape from [shapes]
		{"remove", [&]()
		{
			if(!setValuesFromParameters(
				vector<int*> {&index}
			)) return;
			// make sure shape [index] exists
			if(!validateIndex()) return;
			delete shapes[index - 1];
			// the erase function takes an iterator as an argument
			// and not an int, so we use pointer arithmetic
			shapes.erase(shapes.begin() + index - 1);
		}},

		// this has to exist so that when the user types exit, they don't get
		// a message saying "exit is an invalid command"
		{"exit", [](){}},
	};

	while(userCommand.compare("exit") != 0) 
	{
		// get a command from the user
		cout << "Enter the command: ";
		getline(cin, userCommand);
		cout << endl; // remove me, this is just so that the testing looks neat
		// make a cstring of the same length as the string the user inputted
		// ready to be copied into
		char *cstr = new char[userCommand.length() + 1];

		// !! !! !! !! return this line to use once we are back under the
		// thumb of Bill Gates
		// - strcpy_s(cstr, userCommand.length()+1, userCommand.c_str());
		// also make sure to use strtok_s, too
		// !! !! !! !! and remove this one

		// copy the string into the cstring
		strcpy(cstr, userCommand.c_str());
		 
		// reset the parameter list
		parameters = {};
		// use strtok_s to get token strings
		// strtok_s, when called with a non-null pointer, returns the start of
		// the first token and replaces delimiters
		// (in this case the space character)
		// with null bytes so that individual tokens behave like cstrings
		char *nextToken = strtok(cstr, " ");
		// strtok_s will return a nullptr once we run out of arguments
		while(nextToken != nullptr)
		{
			// this line comes first so that
			// A. it is only executed after we know a token exists
			// B. the first token obtained outside of the loop is pushed back
			parameters.push_back(nextToken);
			nextToken = strtok(nullptr, " ");
		}
		// the first parameter is the command
		string command = parameters[0];

		// try to run the command
		if(userCommands.contains(command)) userCommands[command]();
		else cout << command << " is not a valid command" << endl;
		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...
		cout << endl << endl;
	}
	cout << "Press any key to continue...";
	std::getchar();
	return 0;
}
