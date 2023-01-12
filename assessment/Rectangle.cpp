#include "Rectangle.h"
#include "calculateRectangularPoints.h"

#include <sstream>

// constructor
// sets the value of [leftTop] via the {Shape} constructor
// initialises 4 vertices in [Points] via the {Shape} constructor
// sets the values of [height] and [width]
// calculates the rest of the necessary values
Rectangle::Rectangle(const int &x, const int &y, const int &h, const int &w):
Shape(x, y, 4), height(h), width(w)
{
	// the metrics for the shape have to be calculated as soon as the
	// object is initialized
	//
	// even though this is called in the constructor of every type of shape,
	// it cannot be called in the constructor of the Shape class
	// since it calls virtual methods
	calculateMetrics();
}

// sets the correct value of [area] based on the dimensions of the rectangle
void Rectangle::calculateArea()
{
	// area of a rectangle = witdh * height
	area = abs(width * height);
}

// sets the correct value of [perimeter] based on the dimensions of the rectangle
void Rectangle::calculatePerimeter()
{
	// perimeter of a rectangle = width * height * 2
	perimeter = (abs(width) + abs(height)) * 2;
}

// sets the correct values in [Points] based on the dimensions of the rectangle
void Rectangle::calculatePoints()
{
	// call helper function to calculate points
	calculateRectangularPoints(points, leftTop, height, width);
}

// moves [leftTop] to a specified location and recalulates necessary values
void Rectangle::move(const int &newX, const int &newY)
{
	leftTop = Point(newX, newY);
	calculateMetrics();
}

// maintains the position of [leftTop] and scales the dimensions
// and then recalulates necessary values
void Rectangle::scale(const float &scaleX, const float &scaleY)
{
	width *= scaleX;
	height *= scaleY;
	calculateMetrics();
}

// creates a {string} with the following format:
// returns that {string}
//
// Rectangle[h=50,w=200]
// Points[(100,100)(300,100)(300,150)(100,150)]
// Area=10000.0 Perimeter=500.0
std::string Rectangle::toString() const
{
	using namespace std;
	// use a string stream to make it easier to convert from {int} to {string}
	ostringstream oss;
	// call {Shape}'s [toString] to get all of the rectangles's details
		oss << "Rectangle[h=" << height << ",w=" << width << "]" << endl
	    << Shape::toString();
	return oss.str();
}
