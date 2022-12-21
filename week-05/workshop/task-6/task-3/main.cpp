#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int width, height;

	cout << "Please enter dimensions for a rectangle: ";
	cin >> width >> height;
	Rectangle rect(width, height);
	cout << "A " << width << "x" << height << " rectangle has area "
	     << rect.area() << endl << endl;

	cout << "Please enter dimensions for a triangle: ";
	cin >> width >> height;
	Triangle tri(width, height);
	cout << "A " << width << "x" << height << " triangle has area "
	     << tri.area() << endl;

	return 0;
}
