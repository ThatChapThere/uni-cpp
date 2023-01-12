#include <iostream>
#include <vector>
#include "sortInts.h"
#include "sortLongs.h"
#include "sortDoubles.h"

int main()
{
	using std::vector;
	vector<int> integerVector{1, 3, 61, 6123, 12, 10234, 12, 65};
	vector<long> longVector{1, 3, 61, 6123, 12, 10234, 12, 65};
	vector<double> doubleVector{23, 156.162, 13641, 72.78, 8.9, 283.5, 4.6786, 0.789456};
	printVector(integerVector);
	printVector(longVector);
	printVector(doubleVector);
	sort(integerVector, true);
	sort(longVector, true);
	sort(doubleVector, true);
	printVector(integerVector);
	printVector(longVector);
	printVector(doubleVector);
	return 0;
}
