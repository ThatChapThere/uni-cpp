#include <iostream>

using namespace std;

class A
{
private:
	int value; // this must stay private
public:
	A(int v) : value(v) {}
	void print() { cout << "My value is " << value << endl; }
	friend A add(A a1, A a2);
	A operator+(A a2);
};

A add(A a1, A a2)
{
	return A(a1.value + a2.value);
}

A A::operator+(A a2)
{
	return A(value + a2.value);
}

int main()
{
	A a1 = A(2);
	A a2 = A(3);
	a1.print();
	a2.print();
	A a3 = add(a1, a2);
	a3.print(); // this should display "My value is 5
	A a4 = a1 + a2 + a3;
	a4.print(); // this should be 10
	return 0;
}
