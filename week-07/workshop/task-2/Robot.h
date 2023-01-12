#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>

class Robot
{
// this is changed from private to protected 
// so that they can be accessed by methods of child classes
protected:
	std::string name;
	int workUnit;
	std::vector<int> *_history;
	std::vector<int> *getHistory();
public:
	// you can assign properties with parentheses
	// this is only allowed as part of a constructor definition
	// and works like "string name(s);" would
	Robot(std::string s="default name");
	~Robot();
	void setName(std::string s);
	void whoAmI();
	void work();
	void printWork();
	//int *test;
};

#endif
