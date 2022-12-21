#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::istringstream;
using std::ostringstream;

int main ()
{
	string filepath = "test.txt";
	// there are 3 types associated with filestreams
	fstream filestream(filepath); filestream.close();
	ifstream input_filestream(filepath); input_filestream.close();
	ofstream output_filestream(filepath); output_filestream.close();

	// there are a few functions that you can apply to 
	// filestreams
	filestream.open(filepath);
	filestream.close();
	cout << "is the filestream open? " << filestream.is_open() << endl;

	// some of them are used for validating files
	// for example making sure that they contain a valid eof
	filestream.open(filepath);
	cout << "is the filestream good? " << filestream.good() << endl;
	cout << "is the filestream bad? " << filestream.bad() << endl;
	cout << "does the filestream have a fail bit? " 
	     << filestream.fail() << endl;

	// badbit is more serious than failbit
	// failbit is set if a specific operation
	// like integer conversion fails
	// badbit is set if the stream is fundamentally corrupted
	
	// string streams are another type of stream that will create a string
	// you can use << and >> with them too
	// there are 3 types as with file streams: in, out, and both
	stringstream ss1("this is stream 1");
	ostringstream ss2("this is stream 2");
	istringstream ss3("this is stream 3");

	// you can write to string streams
	ss1 << " more text";
	ss2 << " yet more text";

	cout << ss1.str() << endl;
	cout << ss2.str() << endl;
	cout << ss3.str() << endl;

	// this actually overwrites the streams' strings
	// since the pointer starts at 0
	// there is a way around this if needed, but it's easier to 
	// just initialise a stream that's going to be written to
	// as empty
	stringstream ss4;

	ss4 << "one ";
	ss4 << "word ";
	ss4 << "at ";
	ss4 << "a ";
	ss4 << "time ";

	cout << ss4.str() << endl;
	// and that works
	
	// it works essentially the same as any other stream
	string word;
	while(ss4 >> word)
		cout << word << endl;
	// and the above prints one word at a time
	// since the << operator stops at whitespace
	
	// you can also use str to set the stream
	ss4.str("new value for ss4");

	cout << ss4.str() << endl;
}
