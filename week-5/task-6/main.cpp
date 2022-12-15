//
// CMP2801M Advanced Programming
// Workshop Week 5
// Task 6
// 2022-2023
//

#include <iostream>
#include "Tool.h"
#include "Paper.h"
#include "Rock.h"
#include "Scissors.h"

using namespace std;

int main() {
	// Example main function
	// You may add your own testing code if you like

	Scissors s1(5);
	Paper p1(7);
	Rock r1(15);
	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;

	return 0;
}
