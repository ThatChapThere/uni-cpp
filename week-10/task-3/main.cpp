#include <iostream>
#include <vector>
#include <string>
#include "Animal.h"
#include "Sheep.h"
#include "Cow.h"
#include "Frisian.h"

using std::cout,
      std::cin,
      std::endl,
      std::string,
      std::vector;

int main()
{
	// create a vector of animal pointers
	// you can't create a vector of animals
	// since vector of absract classes cannot exist
	// because std::vector stores values only
	// and abstract classes can't be instantiated
	// so it has to be a vector of pointers
	vector<Animal*> container;

	// get amounts of each animal type from the user
	int numberOfSheep, numberOfCows, numberOfFrisians;
	cout << "How many sheep would you like to add? ";
	cin >> numberOfSheep;
	cout << "How many cows would you like to add? ";
	cin >> numberOfCows;
	cout << "How many frisians would you like to add? ";
	cin >> numberOfFrisians;

	// add those amounts of animals to the container
	for(int i = 0; i < numberOfSheep; i++)
		container.push_back(new Sheep);
	for(int i = 0; i < numberOfCows; i++)
		container.push_back(new Cow);
	for(int i = 0; i < numberOfFrisians; i++)
		container.push_back(new Frisian);
	
	// code snippet from task 3 specification
	// loop through all of the members of container
	for(int a = 0; a < container.size(); a++)
	{
		// previously:
		// --container[a].speak();
		// this had to be changed since the container is a 
		// vector of pointers and not direct values
		container[a]->speak();
	}
	return 0;
}
