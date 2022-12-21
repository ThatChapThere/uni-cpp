#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>
#include "WordCountPair.h"

using std::string;
using std::vector;

class DocSummary
{
	private:
		int numberOfWords;
		int numberOfSentences;
		string filename;
		vector<WordCountPair> wordList;

		void increaseSentenceCount(string word);
		void addWord(string word);
		void removePunctuation(string &word);	
	public:
		DocSummary(string documentName);
		void printSummary();
		void analyseDocument();
};

#endif
