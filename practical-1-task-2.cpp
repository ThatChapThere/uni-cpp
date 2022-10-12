#include <iostream>

using namespace std;

char shifted_char(char character, int shift_amount)
{
	int character_code = character;
	
	if('a' <= character_code && character_code <= 'z')
	{
		character_code += shift_amount;
		if(character_code > 'z') character_code -= 26;
	}
	else if('A' <= character_code && character_code <= 'Z')
	{
		character_code += shift_amount;
		if(character_code > 'Z') character_code -= 26;
	}
	return (char) character_code;
}

int main(int args, char *argv[])
{
	string input_text = argv[1];
	int should_decrypt = stoi(argv[2]);
	int offset = stoi(argv[3]) % 26;

	if(should_decrypt != 0 && should_decrypt != 1) return 0;
	if(should_decrypt) offset = 26 - offset;
	
	for(int i = 0; i < input_text.length(); i++)
		input_text[i] = shifted_char(input_text[i], offset);	
	
	cout << input_text << endl;	
	return 0;
}
