#include <iostream>

using namespace std;

int main()
{
	char cstring_unterminated[3] = {'a', 'b', 'c'};
	cout << cstring_unterminated << endl;
	printf(cstring_unterminated);
}
