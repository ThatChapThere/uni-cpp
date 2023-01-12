#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using std::cout,
	  std::cin,
	  std::string,
	  std::stringstream,
      std::endl;

void variableType(int i)
{
	cout << i << " - this varible is an integer" << endl;  
}

void variableType(double d)
{
	cout << d << " - this varible is a double" << endl;  
}

void variableType(string s)
{
	cout << s << " - this varible was a string" << endl;  
}

int main()
{
	variableType(2);
	variableType(0.123);
	variableType("Lovely weather");
	for(int a = 0; a < 3; a ++)
	{
		stringstream ss;
		string s;
		int i;
		double d;

		cout << "Enter a value: ";
		getline(cin, s);
		// copy the entire string to the stream
		ss = stringstream(s);

		ss >> d;
		if(ss.rdbuf()->in_avail() == 0)
		{
			if(d == floor(d))
			{
				i = d;
				variableType(i);
				continue;
			}
			variableType(d);
			continue;
		}

		variableType(s);
	}
	return 0;
}
