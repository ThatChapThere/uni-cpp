#include <iostream>
#include <fstream>
#include <string>
#include "DocSummary.h"

int main()
{
	std::string filename;
	std::cout << "Please enter the name of the file you wish to analyse" << std::endl;
	std::cin >> filename;

	DocSummary document(filename);
	document.analyseDocument();
	document.printSummary();

	return 0;
}
