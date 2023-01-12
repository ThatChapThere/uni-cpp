#pragma once

#include <string>

class Point
{
private:
	int x, y;
public:
	Point(const int &a, const int &b): x(a), y(b) {}
	// we need a default constructor for when we initialize a shape's points
	// vector
	Point(): Point(0, 0) {}
	Point operator+(const Point &p2) const;
	void operator=(const Point &p2);
	std::string toString() const;
};
