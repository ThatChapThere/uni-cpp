/*
 * Advanced programming is as much about programming techniques as it is conplicated language concepts
 * 
 * Advanced can mean:
 * - Efficiency (of runtime, human time, hardware resources etc.)
 * - Coding concepts (git, OOP, good comments etc.)
 * - Development methodes (TTD, agile etc.)
 * 
 * The module focuses on the programming side of things
 * This will mean a focus on low level concepts
 * 
 * Main module focuses:
 * - Code development
 * - OOP
 * - etc.
 * 
 * C++ is designed to be:
 * - close to the machine
 * - close to the problem to be solved
 * 
 * This means:
 * - direct mappings of language features to machine code
 * - flexible abstraction mechainisms for fast development
 * 
 * This forces C++ to be a tradeoff between human vs computer performance
 * 
 * C++ started off as C with classes and was worked on from 1979 onwards
 * It was commercially released in 1985 and standardised by ISO in 1998
 * 
 * Various features were originally tested in 'feature branches' which eventually became meged in releases
 * 
 * C++ allows for 4 main programming styles
 * - C style
 * - Data abstraction
 * - OOP
 * - Generic programming
 * 
 * C++ is a general purpose programming language and is designed to do as many things as possible
 * 
 * It has a bias towards systems programming though, with low level memory management
 * So it is used for drivers, VMs, OSes, etc.
 * 
 * Proceedural programming:
 *   focused on explicit data management, C style
 * Data abstraction
 *   focused on interfaces and abstract classes
 * OOP
 *   encapsulation and polymorphism
 * Generics
 *   things that use <> tags and allow functions to take in any type where type is not relevant to the actual workings of the function
 *   (like how arrays work for any type)
 * 
 * C++ is used for
 * - robotics
 * - microcontrollers
 * - operating systems
 * - MySQL and other DB software
 * - Engineering and medical applications
 * - Crucial parts of large web companies like Google and Facebook
 * 
 * 
 * 
 */

/* skeleton of a C++ program */

/* this means the header file iostream.h will be used. This library defines standard IO */
#include <iostream>

using namespace std;

/* Note to self: add more notes based on slides */

/* this is the main function which is called on program execution */
int main()
{
	/* the << operator is called the puts operator */
	std::cout << "Hello World!\n" << std::endl;

	/* we can read from the stdin using cin and read into a variable of a defined type */
	int v1 = 0;
	std::cin >> v1;

	std::cout << v1 << std::endl;

	/* quiz */
	cout << "Enter two numbers: " << endl;
	
	int n1 = 0,
	    n2 = 0;

	cin >> n1 >> n2;

	cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << endl;

	/* this indicates the program executed without errors */
	return 0;
}