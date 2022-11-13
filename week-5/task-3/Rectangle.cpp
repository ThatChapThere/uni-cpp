#include "Rectangle.h"

double Rectangle::area()
{
	return width * height;
}

Rectangle::Rectangle(int w, int h): Shape(w, h){}
