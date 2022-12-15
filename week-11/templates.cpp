#include <iostream>

// templates are an example of polymorphism, specifically parametric polymorphism
// parametric polymorphism is when you have a singular function definition, 
// making it a sort of inverse of overloading, which is an example of ad-hoc polymorphism

// it appears that the template line only applies to the funtion or class directly below it
template<typename T>
T add(T a, T b)
{
	return a + b;
}

template<typename T, typename S>
T addTypemixing(T a, S b)
{
	return a + b;
}

// template classes also exist
// templates can include parameters of know type
// "typename" is a sort of dummy type used to represent types
// -template<typename T, int i> class foo
// called with
// -foo<string, 3>
// works somewhat like
// -#define T string
// -#define i 3
// used as macros but only in the context of the class
// this means typed parameters can be used for things like array length
// since they are not varibles, and are replaced with literals at compile time
template<typename T, int length>
class arrayContainer
{
private:
	T arrayContained[length];

public:
	T getItemAt(int index)
	{
		if(index >= length)
		{
			std::cout << "out of bounds" << std::endl;
			return 0;
		}
		return arrayContained[index];
	}
	void setItemAt(int index, T item)
	{
		if(index >= length)
		{
			std::cout << "out of bounds" << std::endl;
			return;
		}
		arrayContained[index] = item;
	}
};

int main()
{
	std::cout << add(1, 3) << std::endl;
	// the following causes a compiler error:
	// -std::cout << add(1, 3.3) << std::endl;
	// this is because when a function using templates is not explicitly called,
	// what happens is that the complier tries to fill in the template,
	// which works somewhat like macros
	std::cout << addTypemixing(1.3, 5) << std::endl;

	arrayContainer<int, 3> exampleContainer;
	exampleContainer.setItemAt(2, 123);
	std::cout << exampleContainer.getItemAt(2) << std::endl;
	exampleContainer.setItemAt(5, 123);
	std::cout << exampleContainer.getItemAt(5) << std::endl;

	return 0;
}
