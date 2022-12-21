#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// chars can be signed or unsigned
	unsigned char uchar;
	signed char schar;
	
	// don't mix signed and unsigned values!!
	cout << ((unsigned) 1) * -1 << " isn't -1!!" << endl;
	
	// you can do C style strings in C++
	// this one won't be terminated
	char cstring_unterminated[3] = {'a', 'b', 'c'};
	// neither will this one
	char cstring_maybe_terminated[] = {'a', 'b', 'c'};

	// this is terminated since the default value for a char is \0
	char cstring_terminated_1[4] = {'a', 'b', 'c'};
	// this is terminated since "" strings always are
	char cstring_terminated[] = "abc";

	// testing cout vs printf in terms of recognising unterminated strings
	cout << cstring_unterminated << endl;
	cout << cstring_maybe_terminated << endl;
	cout << cstring_terminated_1 << endl;
	cout << cstring_terminated << endl;
	printf("%s\n", cstring_unterminated);
	printf("%s\n", cstring_maybe_terminated);
	printf("%s\n", cstring_terminated_1);
	printf("%s\n", cstring_terminated);

	// there are a bunch of cstring functions in the cstring header
	// I'm pretty sure I can remember them, but they should be easy
	// to check
	cout << strcmp("a", "z") << endl;
	
	// C++ has its own string class
	// which works more like other languages
	// imported using the string header
	string string1 = "Hello World"; // copy initialisation
	string string2 = string1;
	string string3("Hello again");
	// you can also make a repeated character like with
	// string "multiplication" in python
	string lots_of_as(100, 'a');
	// you can't do this: string(100, string1);
	
	// when using streams, always put the stream on the left
	cout << string1 << endl;
	// works, but
	// string1 >> cout does not
	
	// there are a couple of important string functions that
	// are not like other languages
	// size and empty
	// instead of length and isEmpty
	// actually, length does exist and is just a call to size
	cout << string1.size() << endl;
	cout << string1.length() << endl;
	cout << string1.empty() << endl;

	// indexing, assignment, concatenation, and comparison are the
	// same as with any other language
	
	// the >> operator actually is whitespace separated
	// not newline separated
	// if you want to get lines, you have to use getline
	// which can be used on filestreams as well as iostreams
	string cinstring, getlinestring;
	cout << "Type something with spaces in it" << endl;
	cin >> cinstring;
	cout << "According to cin, you typed: " << cinstring << endl;

	getline(cin, getlinestring);
	cout << "According to getline, you typed: " << getlinestring << endl;
	// the above actually finishes the cin off with the getline
	// since the buffer isn't empty it doesn't ask for any
	// more input

	// this will work since we already use getline and
	// so there are no newlines in the buffer
	cout << "Type something with spaces in it" << endl;
	getline(cin, getlinestring);
	cout << "According to getline, you typed: " << getlinestring << endl;

	// this will fail in the same way as above and will 
	// output nothing with the second cout
	cout << "Type a single word" << endl;
	cin >> cinstring;
	cout << "According to cin, you typed: " << cinstring << endl;

	getline(cin, getlinestring);
	cout << "According to getline, you typed: " << getlinestring << endl;

	// you can get the last character of a string
	// using stringname[stringname.length() - 1 of course
	// but you can also just use the string back function
	cout << "enter a word: ";
	cin >> cinstring;
	cin >> cinstring;
	// this actually works because getline sees \n as a reason to stop
	// while cin sees it (when on it's own) as a reason to get user
	// input and so asks twice this time
	cout << "the last letter of " << cinstring << " is " << cinstring.back() << endl;

}
