/*Colby Holmes
10/30/2014
Mark Thompson
The purpose of this program is to implementing a stemming algorithm*/
/*Include header files*/
#include <stdio.h> 
#include <string.h>

/*Declare main function*/
int main() 
{ 
/*Create array to hold a string*/
	char word[30];

/*Ask for word and confirm word to user*/	
	printf("Please enter a word to stem: ");
	scanf("%s",word); 
	printf("Initial word: %s\n", word);

/*determine the length of the string*/
	int length = strlen(word);

/*each "if" block checks to see if the string matches the requirements to stem it*/
	if ((word[length - 4] == 's') && (word[length - 3] == 's')
		&& (word[length - 2] == 'e') && (word[length - 1] == 's'))
	{
/*if word ended in "sses" cut out "es"*/
		word[length - 2] = '\0';
	}
	else if (word[length - 1] == 's')
	{
/*if word ended in only 's' cut out the 's' ** necessary to put this after the previous statement*/
		word[length - 1] = '\0';
	}
	else if ((word[length - 2] == 'e') && (word[length - 1] == 'd'))
	{
/*if word ends in "ed" cut it out*/
		word[length - 2] = '\0';
	}

/*print the new word*/
	printf("Stemmed word: %s\n", word);

/*end program*/
	return 0;
}
