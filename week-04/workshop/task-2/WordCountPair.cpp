#include <string>
#include "WordCountPair.h"

using std::string;
WordCountPair::WordCountPair()
{
	word = string();
	Count = 0;
}

WordCountPair::WordCountPair(string w, int c)
{
	word = w;
	Count = c;
}

void WordCountPair::setWord(string w)
{
	word = w;
}

std::string WordCountPair::getWord()
{
	return word;
}

void WordCountPair::setCount(int c)
{
	Count = c;
}

int WordCountPair::getCount()
{
	return Count;
}
