#pragma once

#include "Shape.h"
#include "Movable.h"

class Square: public Shape, public Movable
{
private:
	int edge;
public:
	Square(const int &x, const int &y, const int &e);
	// these all override the parent class methods
	// for the sake of hypothetical extensibility, eg. "blue square"
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
