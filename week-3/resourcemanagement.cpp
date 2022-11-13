#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	// there are a few things that can go wrong with memory in C++
	// you can have a memory leak
	// where the memory just keeps being allocated and not
	// deallocated and fills up the computer's RAM
	// you can accidentally delete a reference too soon while
	// another pointer somewhere points to an object and still needs it
	// you can also accidentally delete something twice
	// that doesn't sound like a problem at first, but
	// if there is a destructor function that gets called
	// too many times it can make everyting go wrong
	
	// there a different segments of memory that a program uses
	// the text segment:
	//     stores the code being executed
	// the data segment:
	//     stores global and static variables
	// the heap:
	//     dynamically allocated variables are stored here
	// the stack:
	//     function parameters and local variables
	//     and any other function data
	//
	// the stack is used for static memory allocation
	// the heap is used for dynamic memory allocation
	//
	// stack:
	//     features:
	//         located near the top of memory
	//         allocation happens on contiguous blocks of memory
	//         allocation and deallocation is automatic
	//     allocation and deallocation process:
	//         memory is allocated for a function every time one is called
	//         more stack memory is allocated when new local variables appear
	//         all of the memory is deallocated on return
	//         all local variables at that point are invalid
	// heap:
	//     allocated and deallocated explicitly always
	//     can cause memory leaks if you don't watch out
	//     allocated and deallocated using new and delete
	//     usage:
	//         use the new keyword followed by a constructor
	//
	//         this will return a pointer to the type that
	//         the constructor creates
	//
	//         use the delete keyword on the pointer variable to
	//         free up memory
	int *dynamic_number = new int(5);
	cout << *dynamic_number << endl;
	delete dynamic_number;
	// at this point the variable dynamic_number is a pointer to 
	// invalid memory
	// and should be reset in most cases
	dynamic_number = nullptr;

	// a couple of other important differences between 
	// the stack and the heap derive from the fact that the heap
	// is larger
	// so the stack will run out of memory faster
	// but the heap is slower to use since it is more fragmented
}
