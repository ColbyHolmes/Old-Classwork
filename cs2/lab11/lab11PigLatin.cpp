/*Colby Holmes 
Lab 11 CSCE 1040
Pig Latin */

#include <iostream>
#include <string>
using namespace std;

int main()
{
//creat storage for user input
	char word[20];
//ask for and read in input
	cout << "Please enter a word: ";
	cin >> word;
//switch based on first letter
	switch(word[0])
	{
//if the first letter is a vowel
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
//print word with yay at the end
		cout << word << "yay" << endl;
		break;
//if anything other than a vowel
	default:
//print each letter starting with the secound
		for(int i=1; i<20; i++)
		{
//if end of string end the loop
			if (word[i] == '\0')
			{
				i = 19;
			}
			else
			{
				cout << word[i];
			}
		}
//print the first letter followed by ay
		cout << word[0] << "ay" << endl;
	}
//end program
	return 0;
}
