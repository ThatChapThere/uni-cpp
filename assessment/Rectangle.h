#pragma once

#include "Shape.h"
#include "Movable.h"

class Rectangle: public Shape, public Movable
{
private:
	int height;
	int width;
public:
	Rectangle(const int &x, const int &y, const int &h, const int &w);
	// these all override the parent class methods
	// for the sake of hypothetical extensibility, eg. "purple rectangle"
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
