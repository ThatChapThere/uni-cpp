#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class WordFreqPair{
	public:
		string word;
		int Count;

		WordFreqPair(string w)
		{
			word = w;
			Count = 1;
		}
};

bool is_alpha(char c)
{
	return 'a' <= c && c <= 'z' ||
	       'A' <= c && c <= 'Z';
}

bool is_sentence_terminator(char c)
{
	switch(c)
	{
		case '.':
		case '!':
		case '?':
			return true;
		default:
			return false;
	}
}

void add_word(vector<WordFreqPair> &wordList, string word, int &wordCount)
{
	if(word == "") return;

	wordCount ++;

	for(auto &freqPair :wordList)
	{
		if(freqPair.word == word)
		{
			freqPair.Count++;
			return;
		}
	}
	wordList.push_back(WordFreqPair(word));
}

int main()
{
	char current_line[1024];
	string filename = "input.txt";
	ifstream file(filename);

	string current_word;
	char current_char;

	int numberOfWords     = 0,
	    numberOfSentences = 0;

	vector<WordFreqPair> wordList{};

	if(file.is_open())
	{
		while(!file.eof()){
			file.getline(current_line, 1024);

			current_word = "";
			
			for(int i = 0; current_line[i] != '\0'; i++)
			{
				current_char = current_line[i];

				if(is_alpha(current_char))
				{
					current_word += current_char;
				}else{
					add_word(wordList, current_word, numberOfWords);
					current_word = "";
				}
				if(is_sentence_terminator(current_char))
					numberOfSentences++;	
			}
			add_word(wordList, current_word, numberOfWords);
		}
	}

	file.close();

	cout << "Number of sentences: " << numberOfSentences << endl;
	cout << "Number of words: " << numberOfWords << endl;
	cout << endl;
	cout << "Word frequencies: " << endl;

	for(auto word :wordList)
	{
		cout << word.word << "\t"
		     << word.Count << "\t"
		     << 100.0f * (double) word.Count / numberOfWords << "\t"
		     << "%" << endl;
	}
}
