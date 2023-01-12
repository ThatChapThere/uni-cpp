#include <sstream>
#include <algorithm>
#include <numbers>
#include "Circle.h"

// constructor
// sets the value of [leftTop] via the {Shape} constructor
// initialises 2 vertices in [Points] via the {Shape} constructor
// sets the value of [radius]
// calculates the rest of the necessary values
Circle::Circle(const int &x, const int &y, const int &r): Shape(x, y, 2, true), radius(r)
{
	// the metrics for the shape have to be calculated as soon as the
	// object is initialized
	//
	// even though this is called in the constructor of every type of shape,
	// it cannot be called in the constructor of the Shape class
	// since it calls virtual methods
	calculateMetrics();
}

// sets the correct value of [area] based on the dimensions of the circle
void Circle::calculateArea()
{
	// area of a circle = pi * r^2
	area = std::numbers::pi * radius * radius;
}

// sets the correct value of [perimeter] based on the dimensions of the circle
void Circle::calculatePerimeter()
{
	// perimeter of a circle = pi * d
	perimeter = std::numbers::pi * radius * 2;
}

// sets the correct value of [perimeter] based on the dimensions of the circle
void Circle::calculatePoints()
{
	// these points are used:
	// 0 __
	//  /  \
	// |    |
	//  \__/
	//      1
	points[0] = leftTop;
	points[1] = leftTop + Point(radius * 2, radius * 2);
}

// moves [leftTop] to a specified location and recalulates necessary values
void Circle::move(const int &newX, const int &newY)
{
	// translate the top left point
	leftTop = Point(newX, newY);
	// translate all of the other points
	calculateMetrics();
}

// maintains the position of [leftTop] and scales the dimensions
// and then recalulates necessary values
void Circle::scale(const float &scaleX, const float &scaleY)
{
	// the logic here is that in programs like photshop
	// when you drag the mouse to resize a circle or square
	// it resizes it within the bounds of the rectangle formed by the mouse
	// and the opposite corner, ie. the minimum of the x and y change
	radius *= std::min(scaleX, scaleY);
	calculateMetrics();
}

// creates a {string} with the following format:
// returns that {string}
//
// Circle[r=50]
// Points[(150,280)(250,380)]
// Area=7854.0 Perimeter=314.2
std::string Circle::toString() const
{
	using namespace std;
	// use a string stream to make it easier to convert from {int} to {string}
	ostringstream oss;
	// call {Shape}'s [toString] to get the rest of the cirles's details
	oss << "Circle[r=" << radius << "]" << endl
	    << Shape::toString();
	return oss.str();
}
