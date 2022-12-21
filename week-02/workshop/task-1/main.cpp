#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(){
	// the idea is to take a set of grades
	// and round them down to the nearest 10
	vector<unsigned> grade{100, 98, 15, 30, 25, 70, 82, 66, 78, 40};
	vector<unsigned> scores(11, 0);

	for(auto i: grade)
		scores[i / 10]++;

	for(auto score: scores)
		cout << score;

	cout << endl;
}
