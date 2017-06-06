/*Colby Holmes
Mark Thompson
CSCE 1030
9/11/2014*/

#include <stdio.h>

int main()
{
	int inputGrade;

	printf("Input grade and receive corresponding letter grade."
	" Either A or B: \n");

	scanf("%d", &inputGrade);

	/* Using if and else-if statements, print the correct letter grade
	 for the input grade. 90 and over print A, else print a B */
	if (inputGrade >= 90)
	{
		printf("You got an A!\n");
	}
	else 
	{
		printf("You got a B.\n");
	}
	
	/*Lab3B work starts here.*/

	int number;

	printf("Please enter an integer:\n");
	scanf("%d", &number);
	printf("You just entered the number: %d\n", number);

	/*This is the find out if the integer is positive, negative, or zero.*/
	if (number > 0)
	{
		printf("You entered a positive number.\n");
	}
	else if (number < 0)
	{
		printf("You entered a negative number.\n");
	}
	else
	{
		printf("You entered the number zero.\n");
	}

	return 0;
}

