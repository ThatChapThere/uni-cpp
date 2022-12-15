#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	protected:
		int width;
		int height;

	public:
		Shape(int w, int h);
		double area();
};

#endif
