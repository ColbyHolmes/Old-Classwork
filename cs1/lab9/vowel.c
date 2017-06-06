/*Colby Holmes
10/23/2014
Mark Thompson
Create a program that keeps record of the number of vowels input by the user and prints back the values of each*/
/*include header files*/
#include <stdio.h>

/*Create main function*/
int main()
{
/*Decleare variables*/
	int vowel[6], i;
	char store;

/*Initialize array to 0*/
	for (i = 0; i < 6; i++)
		vowel[i] = 0;

/*Ask for input*/
	printf("Please enter text. To stop press CTRL-D:\n");

/*Read input until EOF entered*/
	while ((store = getchar()) != EOF)
	{
/*Increment the correct array value if needed*/
		if (store == 'a')
			vowel[0]++;
		else if (store == 'e')
			vowel[1]++;
		else if (store == 'i')
			vowel[2]++;
		else if (store == 'o')
			vowel[3]++;
		else if (store == 'u')
			vowel[4]++;
		else if (store == 'y')
			vowel[5]++;
	}

/*Print the totals of each*/
	for (i = 0; i <= 5; i++)
		printf("\n%d\n", vowel[i]);

/*End program*/
	return 0;
}
