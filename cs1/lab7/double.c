/*Author: Colby Holmes
Date: 10/9/2014
Instructor: Mark Thompson
Purpose: Create a program that computes the square of a number using only addition with a for loop and a do while loop*/
/*Includes the header file*/
#include <stdio.h>
/*Create the main function*/
int main()
{
/*Declare variables*/
	int n, opt, i = 0, result = 0;
/*Prompt user for both inputs*/
	printf("Please enter an integer value to be squared: ");
	scanf("%d", &n);
	printf("Excellent. Now would you like to square that with a(n):\n\t1: for-loop\n\t2: do-while loop\n");
	scanf("%d", &opt);

/*Switch statement for the menu*/
	switch(opt)
	{
/*for loop case increments result by n during each iteration*/
		case 1:
			for(i; i < n; i++)
				result += n;
			break;
/*do-while case also increments result by n during each iteration*/
		case 2:
			do{
				result += n;
				i++;
			}while(i<n);
	}
/*prints out the result for th euser*/	
	printf("\nThe result of squaring %d is: %d.\n", n, result);
/*ends the program*/
	return 0;
}
