/*Author: Colby Holmes
Date: 10/02/14
Instructor: Mark Thompson
Purpose: Print out the number of calender days based on inputted month using switch statements*/
/*Includes header file*/
#include <stdio.h>

/*Creates function main to house program*/
int main()
{
/*Declares variables*/
	int month, year;
	
/*Asks for and scans in the month*/
	printf("Please enter the current month in integer form: ");
	scanf("%d", &month);

/*Creates a switch for each of the months*/
	switch(month)
	{
/*Months with 31 days*/
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
/*prints the days*/
			printf("This month has 31 days total.\n");
/*Breaks the switch*/		
			break;
/*Months with 30 days*/
		case 4:
		case 6:
		case 9:
		case 11:
/*Prints the days*/
			printf("This month has 30 days total.\n");
/*Breaks the switch*/		
			break;
/*February*/
		case 2:
/*asks for ans scans in the year **Extra Credit**/
			printf("Oh! Please enter the current year: ");
			scanf("%d", &year);
/*If the year is divisable by 4 with no remainder it is a leap year. This tests that.*/			
			if (year % 4 == 0)
				printf("This is a leap year! There are 29 days.\n");
			else
				printf("This is not a leap year, so there are only 28 days.\n");		
/*Breaks the switch*/
			break;
/*Invalid entry to default*/
		default:
			printf("\nThe number you entered is not a correct entry.\n");
	}
/*Ends the program.*/
return 0;
}
