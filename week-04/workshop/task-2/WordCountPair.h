#ifndef WORDCOUNTPAIR_H
#define WORDCOUNTPAIR_H

#include <string>

using std::string;

class WordCountPair
{
	private:
		string word;
		int Count;

	public:
		WordCountPair();
		WordCountPair(string w, int c=1);
		void setWord(string w);
		string getWord();
		void setCount(int c);
		int getCount();
};

#endif
