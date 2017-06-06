/*Author: Colby Holmes
Date: 10/02/14
Instructor: Mark Thompson
Purpose: Create a switch to display information based on user input*/
/*#include compiles the program with the header file*/
#include <stdio.h>

/*Creates a main function to house the program*/
int main()
{
/*Declares variables*/
	int value, choice;
/*Asks for user to give a value to 'value'*/
	printf("Input a value: \n");
/*Scans that value into the location of 'value*/
	scanf("%d", &value);

/*prints four options to the screen associated with the 
functionality of the switch statement below: */
	printf("\nExcellent! Now would you like to:\n\t1. Add 1\n\t"
		"2. Subtract 1\n\t3. Double it\n\t4. Half it\n");
/*Scans in the users choice to the location of 'choice'*/
	scanf("%d", &choice);
/*Creates a switch for the choices of the user inputted 'choice'*/
	switch(choice)
	{
/*-Increase the value by 1*/
		case 1:
/*Prints value incremented*/
			printf("\nNew value: %d\n", ++value);
/*Quits the switch*/
			break;
/*-Decrease the value by 1*/
		case 2:
/*Prints value decremented*/
			printf("\nNew value: %d\n", --value);
/*Quits the switch*/
			break;
/*-Double the value*/
		case 3:
/*Prints value doubled*/
			printf("\nNew value: %d\n", value *=2);
/*Quits the switch*/
			break;
/*-Half the value*/
		case 4:
/*Prints value halfed*/
			printf("\nNew value: %f\n", (float) value / 2); 
/*-Understand that a default is not needed */
	}
/*Ends the program*/
return 0;
}
/*Enough comments?*/
