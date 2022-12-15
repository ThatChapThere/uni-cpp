#pragma once

#include <iostream>

#define MAXROWS	1000
#define MAXCOLS	1000

template <typename T>
class matrix
{
	private:
		T arr[MAXROWS][MAXCOLS];
		int rows;
		int cols;
		bool inRange(int row, int col)
		{
			if(row < 0 || rows <= row) return false;
			if(col < 0 || cols <= col) return false;
			return true;
		}
		bool rangeCheck(int row, int col)
		{
			if(!inRange(row, col))
				std::cout << "out of range" << std::endl;
			return inRange(row, col);
		}
	public:
		matrix(int height, int width): rows(height), cols(width) {}
		void setElement(int row, int col, T val)
		{
			arr[row][col] = val;
		}
		T getElement(int row, int col)
		{
			return arr[row][col];
		}
};
