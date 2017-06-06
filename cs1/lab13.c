/*Colby Holmes
Mark Thompson
11/20/2014
Create a program that can either reverse user string input or store a string including spaces

Include header files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Function Prototypes*/
void reverseString(char text[]);
void createString(char* dynText, char text[]);
/*Main function*/
int main()
{
/*declare variables*/
	int slen;
	char inputText[100], *pLarge;
/*Ask for inputs*/
	printf("Give a Command:\n");	
/*Scan in string*/
	scanf("%[^\n]c", inputText);
/*Find length for dyn allocation*/
	slen = strlen(inputText + 1);
	pLarge = (char*) malloc(slen * sizeof(char));

/*control flow based on user input*/
	if (!strncmp(inputText, "reverse", 7))
	{
		printf("Reversing Word...\n");
/*call reverse word function*/
		reverseString(inputText);
	}
	else if (!strncmp(inputText, "create", 6))
	{
		printf("Creating Dynamic String...\n");
/*call create string function*/
		createString(pLarge, inputText);
/*Release memory*/
		free(pLarge);	
	}
	else if (!strncmp(inputText, "exit", 4))
	{
		printf("Goodbye!\n");
/*exit function*/
		exit(0);
	}
	else
		printf("Sorry, that command isn't recognized.");
/*loop funtion*/
	main();
	return 0;
}

/*Function definition*/
void createString(char* dynText, char text[])
{	
		
}
/*function definition*/
void reverseString(char text[])
{
	int length, i;
	length = strlen(text) - 8;

/*print each letter starting from the end and ignoring the initial command*/
	for (i=0; i<length; i++)
	{
		printf("%c", text[7 + length -i]);
	} 
	printf("\n\n");
}
