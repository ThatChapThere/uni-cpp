#pragma once

#include <string>
#include <vector>
#include "Point.h"

class Shape
{
// these members have to be protected and not private so that derived classes
// can access them
protected:
	float area;
	bool isCircular = false;
	Point leftTop;
	float perimeter;
	std::vector<Point> points;
	void calculateMetrics();
public:
	Shape(const int &x, const int &y, const int &pointCount, const bool &c=false):
		leftTop(x, y), isCircular(c), points(pointCount) {}
	// pure virtual functions
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	// impure virtual function - this is needed to prevent code repetition
	// since most of the details to be printed do not depend on the shape
	// we can have a universal [toString] which gets called by the
	// child [toString] implementations
	// it is declared const so that functions using a {const &Shape}
	// can call [toString]
	virtual std::string toString() const;
};

// functions have to be declared in header files in order to be used in other
// places even when they are standalone and not methods
// these functions send the value of toString() to a stream for either a 
// shape or a pointer to a shape
// and return said stream
std::ostream& operator<<(std::ostream &os, const Shape &shape);
std::ostream& operator<<(std::ostream &os, Shape *shape);
