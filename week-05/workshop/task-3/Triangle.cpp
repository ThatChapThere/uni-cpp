#include "Triangle.h"

double Triangle::area()
{
	return width * height / 2.0;
}

Triangle::Triangle(int w, int h): Shape(w, h){}
