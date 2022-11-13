#include <iostream>

// Namespaces exist to prevent name collision
// we can make two namespaces below and have a two 
// functions with the same name
namespace namespace1
{
	void doTheThing()
	{
		std::cout << "Hey! namespace1 here!" << std::endl;
	}
}

namespace namespace2
{
	void doTheThing()
	{
		std::cout << "Hi there I guess. I am namespace2." << std::endl;
	}
}

int main()
{
	// there are two key ways of accessing namespaces
	// number one is just the namespace resolution operator
	namespace1::doTheThing();
	namespace2::doTheThing();

	// the second is the using directive
	// this is scoped, which is useful
	{
		using namespace namespace1;
		doTheThing();
	}

	{
		using namespace namespace2;
		doTheThing();
	}
		 
	return 0;
}
