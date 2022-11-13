#include "DocSummary.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::vector;

void DocSummary::removePunctuation(string &word)
{
	string newWord("");
	for(char c: word)
		if(
			('a' <= c && c <= 'z')||
			('A' <= c && c <= 'Z')
		  ) newWord += c;
	word = newWord;
}

void DocSummary::increaseSentenceCount(string word)
{
	for(char c: word)
	{
		switch(c)
		{
			case '.':
			case '!':
			case '?':
				numberOfSentences++;
		}
	}
}

void DocSummary::addWord(string word)
{
	numberOfWords++;
	for(auto &wordCountPair: wordList)
	{
		if(wordCountPair.getWord() == word)
		{
			wordCountPair.setCount(wordCountPair.getCount() + 1);
			return;
		}
	}
	wordList.push_back(WordCountPair(word));
}

DocSummary::DocSummary(string documentName)
{
	filename = documentName;
	numberOfSentences = 0;
	numberOfWords = 0;
}

void DocSummary::printSummary()
{
	std::cout << "number of sentences is " << numberOfSentences << std::endl;
	std::cout << "number of words is " << numberOfWords << std::endl;

	for(auto wordCountPair: wordList)
		std::cout << wordCountPair.getWord() << "\t" << wordCountPair.getCount() << std::endl;
}

void DocSummary::analyseDocument()
{
	string currentWord;
	std::ifstream file(filename);
	while(file >> currentWord)
	{
		increaseSentenceCount(currentWord);
		removePunctuation(currentWord);
		addWord(currentWord);
	}
	file.close();
}
