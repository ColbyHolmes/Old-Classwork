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

	return 0;
}

