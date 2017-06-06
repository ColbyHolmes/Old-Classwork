/*Colby Holmes
CSCE 1030-001
Mark Thompson
9/18/2014
Wealth.c is a program that computes compound interest for the user.*/

#include <stdio.h>

int main()
{
	/*Variable Declaration*/
	int years;
	double investment;
	
	/*Prompt user and receive inputs*/
	printf("--------Welcome to the Compound Interest Calculator!--------\nTo calculate the interest you need "
		"to enter how many years you would like to invest and the amount you will be investing.\n\n"
		"Years: ");
	scanf("%d", &years);
	
	printf("\nAmount Invested: ");
	scanf("%lf", &investment);

	/*Loop to calculate yearly increments and return values to user
	Intialization variable*/
	int i;
	for (i = 1; i <= years; i++)
	{
		investment = investment + investment * .06;
 		printf("\nYear: %d\tInvestment increased by 6%\tValued at: $%.2lf \n", i, investment);
	}

	/*Return to end the program*/
	return 0;
}
