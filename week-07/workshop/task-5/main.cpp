#include "A.h"

// never put using directives in header files
//using std::string
// since header files will be copied into any file that includes them
int main()
{
	A *a1 = new A("a");
	a1->setName("IamA");
	A a2 = *a1;
	a2.printName();
	delete a1;
	a2.printName();
}
