#include <sstream>
#include "Shape.h"

// this is a helper function that calls of the calculation functions
// that need to be called after the shape's dimensions have been changed
void Shape::calculateMetrics()
{
	// these are virtual methods
	// as such, they can be called from another method, since any instance
	// should implement them
	// however, they cannot be called from a constructor, since constructors
	// are called before the child class is constructed
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}

// creates a {string} with the following format:
// returns that {string}
//
// Points[(100,100)(300,100)(300,150)(100,150)]
// Area=10000.0 Perimeter=500.0
std::string Shape::toString() const
{
	using namespace std;
	// create a string stream to make it easier to convert from numbers to strings
	ostringstream oss;
	// format floats to 1 decimal place
	oss.precision(1);
	oss.setf(ios::fixed, ios::floatfield);
	// add all of the points to the stream
	oss << "Points[";
	for(const auto &point: points)
	{
		oss << point.toString();
	}
	oss << "]" << endl;
	// add the area and perimeter to the stream
	oss <<  "Area="      << area;
	oss << " Perimeter=" << perimeter << endl;
	return oss.str();
}

// overloads the "<<" operator for output streams so that you don't have
// to call [toString] to use [cout] with an instance of {Shape}
// returns the output stream
//
// Shape doesn't have to be const here, but it's good practice to make it const
std::ostream& operator<<(std::ostream &os, const Shape &shape)
{
	return os << shape.toString();
}

// overloads the "<<" operator for output streams so that you don't have
// to call [toString] to use [cout] with an instance of {Shape*}
// returns the output stream
//
// this exists since we often use pointers to objects, especially for
// collections like {vector}
std::ostream& operator<<(std::ostream &os, Shape *shape)
{
	return os << shape->toString();
}
