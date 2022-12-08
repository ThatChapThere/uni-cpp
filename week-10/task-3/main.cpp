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
	vector<Animal*> container;
	int numberOfSheep, numberOfCows, numberOfFrisians;
	cout << "How many sheep would you like to add? ";
	cin >> numberOfSheep;
	cout << "How many cows would you like to add? ";
	cin >> numberOfCows;
	cout << "How many frisians would you like to add? ";
	cin >> numberOfFrisians;
	for(int i = 0; i < numberOfSheep; i++)
		container.push_back(new Sheep);
	for(int i = 0; i < numberOfCows; i++)
		container.push_back(new Cow);
	for(int i = 0; i < numberOfFrisians; i++)
		container.push_back(new Frisian);
	
	for(int a = 0; a < container.size(); a++)
	{
		// previously:
		// container[a].speak();
		container[a]->speak();
	}
	return 0;
}
