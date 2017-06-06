/*Colby Holmes
CSCE 1040
2/5/2015
Lab 2 Assignment*/

/*include header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*function prototype*/
void teesAndStuff(int *, int *, char *);

/*declare main function*/
int main()
{
/*declare necessary variables*/
	char *words[20];
	int length, i, count, ascii;

/*create space for, and read in words*/
	for (i=0; i<20; i++)
	{
		words[i] = NULL;
		scanf("%d", &length);
		words[i] = (char *) (malloc((length +1) * sizeof(char)));
		scanf("%s", words[i]);
	}

/*hard code print format*/
	printf("12345678901234567890123456789\n");


	for (i=0; i<20; i++)
	{
/*intialize values and reset for each word*/	
		count = 0;
		ascii = 0;
/*call function*/
		teesAndStuff(&count, &ascii, words[i]);
/*print each word and other information*/
		printf("%15s %1d %9d\n", words[i], count, ascii);
	}
/*end program*/
	return 0;
}

/*function header*/
void teesAndStuff(int *count, int *ascii, char *word)
{
/*declare increment variable*/
	int i;

/*check each letter of the word*/
	for (i=0; i<strlen(word); i++)
	{
/*if a 't' add to count*/
		if (word[i] == 't')
			*count += 1;
/*add the the ascii total*/
		*ascii += word[i];
	}
/*return to main*/
	return;
}
