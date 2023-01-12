#include <iostream>
#include "sortDoubles.h"

void sortRegion(vector<double> &vec, int startIndex, int endIndex)
{
	if(startIndex >= endIndex) return;
	double pivot = vec[endIndex];
	vector<double> largerValues,
	             smallerValues;
	for(unsigned i = startIndex; i < endIndex; i++)
	{
		if(vec[i] < pivot) smallerValues.push_back(vec[i]);
		else largerValues.push_back(vec[i]);
	}
	int replacementPoint = startIndex;
	for(unsigned i = 0; i < smallerValues.size(); i++)
	{
		vec[replacementPoint++] = smallerValues[i];
	}
	int pivotPoint = replacementPoint;
	vec[replacementPoint++] = pivot;
	for(unsigned i = 0; i < largerValues.size(); i++)
	{
		vec[replacementPoint++] = largerValues[i];
	}
	sortRegion(vec, startIndex, pivotPoint - 1);
	sortRegion(vec, pivotPoint + 1, endIndex);
}

void sort(vector<double> &vec, bool ascending)
{
	sortRegion(vec, 0, vec.size());
	if(!ascending)
	{
		int temp;
		for(unsigned i = 0; i < vec.size() / 2; i++)
		{
			temp = vec[i];
			vec[i] = vec[vec.size() - i - 1];
			vec[vec.size() - i - 1] = temp;
		}
	}
}

void printVector(const vector<double> &vec)
{
	using std::cout,
	      std::endl;
	cout << "[";
	for(unsigned i = 0; i < vec.size() - 1; i++) cout << vec[i] << ", ";
	cout << vec[vec.size() - 1] << "]" << endl;
}
