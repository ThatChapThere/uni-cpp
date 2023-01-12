#include <sstream>
#include "Point.h"

// overloadig the sum operator for [Point] makes things much easier
// when we want to set points relative to a specific Point,
// like [Shape.leftTop]
Point Point::operator+(const Point &p2) const
{
	return Point(x + p2.x, y + p2.y);
}

// overloadig the assignment operator for Point means that the program doesn't
// have to initialize any more new objects than necessary
void Point::operator=(const Point &p)
{
	x = p.x;
	y = p.y;
}

// this function makes the [toString] method of [Shape] easier to implement and
// lets us keep the values of [x] and [y] encapsulated as private
// and we don't need to even make [Shape] a friend class of [Point]
std::string Point::toString() const
{
	// create a string stream to make it easier 
	// to convert from numbers to strings
	std::ostringstream oss;
	oss << "(" << x << "," << y << ")";
	return oss.str();
}
