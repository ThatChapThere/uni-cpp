#ifndef CLASSCHILD_H
#define CLASSCHILD_H

#include <iostream>
#include <string>
#include "ClassParent.h"

class ClassChild: public ClassParent
{
private:
	std::string message;
public:
	ClassChild();
	~ClassChild();
	std::string hello();
};

#endif
