#include <iostream>
using namespace std;

// to be completed
void swapv(int x, int y)
{
	int aux = x;
	int *x_addr = &x;
	int *y_addr = &y;
	*x_addr = y;
	*y_addr = aux;
}

void swapr(int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void swap(int &x, int &y)
{
	int aux = x;
	x = y;
	y = aux;
}

void (*pf)(int &x, int &y);

int main()
{
	int a = 2;
	int b = 3;

	printf("%d,%d \n", a, b);
	swapr(&a, &b);
	printf("%d,%d \n", a, b);
	pf = &swap;
	pf(a, b);
	printf("%d,%d \n", a, b);
	swapv(a, b);
	printf("%d,%d \n", a, b);
	return 0;
}

