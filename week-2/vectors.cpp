#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){
	// vectors are like arrays except they can change length
	// vectors are not a type, they are a template
	// they are a part of the C++ STL (standard template library)
	// they are intialised just like templates in C#
	vector<int> numbers;
	
	// you can intialise them with a length
	int numberOfNumbers = 10;
	vector<int> tenNumbers(numberOfNumbers);
	
	// you can also use list intialisation
	vector<int> piDigits{3, 1, 4, 1, 5};

	// vectors are assigned by value, no reference like in
	// higher level languages
	// you can also do the multiplicative initialiser like
	// with strings
	// the first argument is the count
	// so this will be twelve ones
	vector<int> original(12, 1);
	vector<int> copy = original;
	copy[0] = 2;
	cout << "the original still starts with a " << original [0] << endl;

	// you can reinitialise a vector using list notation
	// without specifying a type like you have to in C#
	numbers = {1, 2, 3};
	
	// there are a couple of important vector functions
	cout << "is the vector empty? " << original.empty() << endl;
	cout << "what is the size of the vector? " << original.size() << endl;

	// you can also do == < > <= >= with vectors
	// which works like strings going from first to last
	cout << "is the original greater than the copy? "
	     << (original > copy)
	     << endl;

	// now for the exercise in the lecture
	// the idea is to take a set of grades
	// and round them down to the nearest 10
	vector<unsigned> grade{100, 98, 15, 30, 25, 70, 82, 66, 78, 40};
	vector<unsigned> scores(11, 0);

	for(vector<unsigned>::iterator i = grade.begin(); i != grade.end(); i++)
		scores[*i / 10]++;

	for(auto i = scores.begin(); i != scores.end(); i++)
		cout << *i << endl;

	for(auto score: scores)
		cout << score << " ";
	cout << endl;
	// a couple of notes here:
	// the type of i needs to be vector<T>::iterator
	// but you can also use auto
	// the iterator is a pointer type, not a value type
	// and so must be dereferenced
	// the way that "foreach" loops work in C++ is by using the
	// begin and end functions (except it takes a value or a reference
	// and not a pointer)
	// begin is a pointer to the start of the vector
	// end is a pointer to the first location in memory outside of
	// the pointer, so dereferencing it is undefined behaviour
	// and of course ++ when used on pointers moves them across
	// by the size of their value type in bytes
}
