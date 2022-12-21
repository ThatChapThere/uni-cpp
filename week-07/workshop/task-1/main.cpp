#include <iostream>

using std::cout,
      std::endl;

int add(int a, int b)
{
	return a + b;
}

// this causes a compiler error:
// ambiguation new declaration
//float add(int a, int b)
//{
//	return a + b;
//}

float add(float a, int b)
{
	return a + b;
}

float add(int a, float b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

int main()
{
	int wholeNumber = 10;
	float decimalNumber = 14.62;

	cout << add(wholeNumber, wholeNumber) << endl;
	// this one obviously just does the same thing
	cout << add(wholeNumber, wholeNumber) << endl;
	cout << add(decimalNumber, wholeNumber) << endl;
	cout << add(wholeNumber, decimalNumber) << endl;
	cout << add(decimalNumber, decimalNumber) << endl;

	return 0;
}
