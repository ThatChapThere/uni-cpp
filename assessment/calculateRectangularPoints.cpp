#include "calculateRectangularPoints.h"

// there are a few ways to solve the rendundancy problem where
// both squares and rectangles use the same code
// to calculate their verteces
//
// one is to make an abstract {Rectangular} class with this function as a
// this would still the number of arguments needed, since [points] and [leftTop]
// would be fields
// but a {Rectangular} class would have to inherit from {Shape} to access
// [leftTop] and [points] and then {Square} and {Rectangle} would have two
// paths to the {Shape} class which would cause ambiguous inheritance errors
//
// since this is just a simple function it doesn't really warrant
// its own class and can just be standalone
void calculateRectangularPoints
(std::vector<Point> &points, const Point &leftTop, const int &height, const int &width)
{
	// the points are ordered clockwise
	// 0--1
	// |  |
	// 3--2..(2, 3) -> add y
	//    :
	//  (1, 2) -> add x
	//
	for(int i = 0; i < 4; i++) points[i] = leftTop + Point(
		width  * (0 < i && i < 3),
		height * (1 < i));
}
