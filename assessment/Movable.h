#pragma once

#include "Point.h"

class Movable
{
public:
	// these are pure virtual functions
	virtual void move(const int &newX, const int &newY) = 0;
	virtual void scale(const float &scaleX, const float &scaleY) = 0;
};
