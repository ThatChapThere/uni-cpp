#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
public:
	// was previously
	// -- void speak(void) = 0;
	// but it has to be virtual for the program to work
	virtual void speak(void) = 0;
};

#endif
