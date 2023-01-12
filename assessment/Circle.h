#pragma once

#include "Shape.h"
#include "Movable.h"

class Circle: public Shape, public Movable
{
private:
	int radius;
public:
	Circle(const int &x, const int &y, const int &r);
	// these all override the parent class methods
	// for the sake of hypothetical extensibility, eg. "red circle"
	// these are left override instead of final
	// {Shape} methods
	void calculateArea() override;
	void calculatePerimeter() override;
	void calculatePoints() override;
	std::string toString() const override;
	// {Movable} methods
	void move(const int &newX, const int &newY) override;
	void scale(const float &scaleX, const float &scaleY) override;
};
