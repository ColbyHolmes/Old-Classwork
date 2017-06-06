/*Author: Colby Holmes
Date: 10/16/2014
Instructor: Mark Thompson
Purpose: Write a program that uses functions to calculates factorials

Include header file*/
#include<stdio.h>
/*Function prototypes*/
int factorial(int n);
void printFac(int result);

/*Declare main function*/
int main()
{
/*Variable declaration then initialization through user input*/
	int input;
	printf("\nPlease enter an integer to calculate its factorial value: ");
	scanf("%d", &input);

/*Calls factorial() with argument 'input' then sends this result to printFac()*/
	printFac(factorial(input));

/*Ends program*/	
	return 0;
}

/*Function definition*/
int factorial(int n)
{
/*declare count variable for 'for' loop*/
	int i;
/*for loop to calculate the factorial*/
	for (i = n-1; i > 0; i--)
	{
		n *= i;
	}
/*return factorial  value*/
	return n;
}

/*Funtion definition*/
void printFac(int result)
{
/*Print out the factorial value*/
	printf("\nThe result of the factorial is: %d\n\n", result);
/*Void function, run off edge back to main*/
}	
