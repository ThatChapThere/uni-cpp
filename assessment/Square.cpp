#include "Square.h"
#include "calculateRectangularPoints.h"

#include <sstream>
#include <algorithm>

// constructor
// sets the value of [leftTop] via the {Shape} constructor
// initialises 4 vertices in [Points] via the {Shape} constructor
// sets the value of [edge]
// calculates the rest of the necessary values
Square::Square(const int &x, const int &y, const int &e): Shape(x, y, 4), edge(e)
{
	// the metrics for the shape have to be calculated as soon as the
	// object is initialized
	//
	// even though this is called in the constructor of every type of shape,
	// it cannot be called in the constructor of the Shape class
	// since it calls virtual methods
	calculateMetrics();
}

// sets the correct value of [area] based on the dimensions of the square
void Square::calculateArea()
{
	// area of a square = edge^2
	area = abs(edge * edge);
}

// sets the correct value of [perimeter] based on the dimensions of the square
void Square::calculatePerimeter()
{
	// perimeter of a square = edge * 4
	perimeter = abs(edge * 4);
}

// sets the correct values in [Points] based on the dimensions of the square
void Square::calculatePoints()
{
	// call helper function to calculate points
	calculateRectangularPoints(points, leftTop, edge, edge);
}

// moves [leftTop] to a specified location and recalulates necessary values
void Square::move(const int &newX, const int &newY)
{
	leftTop = Point(newX, newY);
	calculateMetrics();
}

// maintains the position of [leftTop] and scales the dimensions
// and then recalulates necessary values
void Square::scale(const float &scaleX, const float &scaleY)
{
	// the logic here is that in programs like photshop,
	// when you drag the mouse to resize a circle or square
	// it resizes it within the bounds of the rectangle formed by the mouse
	// and the opposite corner, ie. the minimum out of the x or y change
	edge *= std::min(scaleX, scaleY);
	calculateMetrics();
}

// creates a {string} with the following format:
// returns that {string}
//
// Square[e=30] 
// Points[(200,250)(230,250)(230,280)(200,280)] 
// Area=900.0 Perimeter=120.0 
std::string Square::toString() const
{
	using namespace std;
	// use a string stream to make it easier to convert from {int} to {string}
	ostringstream oss;
	// call {Shape}'s [toString] to get the rest of the square's details
	oss << "Square[e=" << edge << "]" << endl
	    << Shape::toString();
	return oss.str();
}
