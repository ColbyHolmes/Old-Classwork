/*Author: Colby Holmes
Date: 10/9/2014
Instructor: Mark Thompson
Purpose: Create a for loop that prints values in range -2 - 8 */
/*Includes header function*/
#include <stdio.h>
/*creates the main function*/
int main()
{
/*Declare variables*/
	int i;
/*for loop true while i = -2 through 8*/
	for(i = -2; i <= 8; i++)
	{
/*Prints each iteration*/
		printf("%d ", i);
	}
/*Prints newline for clarity*/	
	printf("\n");
/*Ends the program*/
	return 0;
}
 
