/*Colby Holmes
CSCE 1030
Mark Thompson
9/25/14
This program is a basic character encoder that makes spaces newlines and prints newline when a newline character is used*/

#include<stdio.h>

/*Main function declaration*/
int main()
{
	/*Opening statement*/
	printf("This program encodes whatever you type!\nEnter 0 to quit.\n"
		"Give it a whirl:");
	
	/*variable declation*/
	char x;
	
	/*Loop to read all characters in*/
	while((x = getchar()) != '0')
	{
		/*If to handle odd putchar() cases*/
		if (x == 'Z')
			putchar('A');
		else if (x  == 'z')
			putchar('a');
		else if ((x >= 'A' && x < 'Z') || (x >= 'a' && x < 'z'))
			putchar(x + 1);
		/*LAB5C work right here!*/
		else if (x == ' ')
			putchar(10);
		else if (x == 10)
			printf("NEW LINE");
		else
			putchar(x);
	}
	
	/*Ends program*/
	return 0;
}
