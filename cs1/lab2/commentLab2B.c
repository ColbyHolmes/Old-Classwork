/*
Author: Colby Holmes
Date: 9/4/2014
Instructor: Thompson
Purpose: Prints 2 basic statements about programming and my expectations.
*/

#include <stdio.h>

int main()
{
	/*Print Statement*/
	printf("Hello World! This is -NOT- my first program.\n");
	
	/*Declares variables*/
	int finalGrade = 99;
	char letterGrade = 'A';

	/*prints another statement*/
	printf("I, Colby Holmes, expect to get a %d, or at least a(n) %c,  in this course.\n", finalGrade,
	letterGrade);

	/*Ends Program*/
	return 0;
}
