#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class WordFreqPair
{
	public:
		string word;
		int count;
		WordFreqPair(string w)
		{
			word = w;
			count = 1;
		}
};

string word{};

int Count,
    numberOfWords,
    numberOfSentences;

string filename;

vector<WordFreqPair> wordList;

void printSummary()
{
	cout << "number of sentences is " << numberOfSentences << endl;
	cout << "number of words is " << numberOfWords << endl;
	for(auto freqPair: wordList)
		cout << freqPair.word << "\t" << freqPair.count << endl;
}

void updateSentenceCount(string word)
{
	for(char c: word)
	{
		switch(c)
		{
			case '.':
			case '!':
			case '?':
				numberOfSentences++;
				break;
			default:
				break;
		}
	}
}

void removePunc(string &word)
{
	string newString = "";
	for(char c: word)
	{
		switch(c)
		{
			case '.':
			case ',':
			case '!':
			case '?':
				break;
			default:
				newString += c;
		}
	}
	word = newString;
}

void addWord(string word)
{
	for(auto &freqPair: wordList)
	{
		if(word == freqPair.word)
		{
			freqPair.count++;
			return;
		}
	}
	wordList.push_back(WordFreqPair(word));
}

void analyseDocument()
{
	ifstream file(filename);
	while(file >> word)
	{
		updateSentenceCount(word);
		removePunc(word);
		addWord(word);
		numberOfWords++;
	}
}

int main()
{
	cout << "Please enter the name of the file you wish to analyse: " << endl;
	cin >> filename;

	analyseDocument();

	printSummary();
}
