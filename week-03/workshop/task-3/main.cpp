#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

void getStatistics(
	vector<string> list,
	vector<string>& listOfDistinctWords,
	vector<int>& listOfCounts
){
	for(string s: list)
	{
		// remove punctuation
		string unpunctuated = "";
		for(char c: s)
		{
			if(
				'a' <= c && c <= 'z' ||
				'A' <= c && c <= 'Z'
			) unpunctuated += c;
		}

		// test if the word is already listed
		bool newWord = true;
		for(unsigned i = 0; i < listOfDistinctWords.size(); i++)
		{
			if(listOfDistinctWords[i] == unpunctuated)
			{
				listOfCounts[i]++;
				newWord = false;
				break;
			}
		}

		// if the word is not already listed
		if(newWord)
		{
			listOfDistinctWords.push_back(unpunctuated);
			listOfCounts.push_back(1);
		}
	}
}

int searchWord(
	string searchedWord,
	vector<string> listOfDistinctWords,
	vector<int> listOfCounts)
{
	for(unsigned i = 0; i < listOfDistinctWords.size(); i++)
		if(listOfDistinctWords[i] == searchedWord)
			return listOfCounts[i];

	return 0;
}

vector<string> readFromFile(string filename)
{
	ifstream file(filename);
	string word;
	vector<string> words;

	while(file >> word)
		words.push_back(word);

	return words;
}

int main()
{
	cout << "Please enter the name of the file you would like to analyse: ";
	string filename;
	cin >> filename;

	vector<string> file_contents = readFromFile(filename);

	vector<string> listOfDistinctWords;
	vector<int> listOfCounts;

	getStatistics(file_contents, listOfDistinctWords, listOfCounts);

	string wordToSearchFor;
	int wordToSearchForCount;

	cout << "Please enter the word you wish to search for: ";
	cin >> wordToSearchFor;

	wordToSearchForCount = searchWord(
		wordToSearchFor,
		listOfDistinctWords,
		listOfCounts
	);

	cout << "The word " << wordToSearchFor 
	     << " occurs " << wordToSearchForCount << " times." << endl;

	return 0;
}
