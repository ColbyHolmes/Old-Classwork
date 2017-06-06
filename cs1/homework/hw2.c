/*Colby Holmes
CSCE 1030-001
Mark Thompson
9/18/2014
This program is a cimple calculator that uses a switch statement to navigate the menu.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
/*variable declaration*/
	int choose = 0;
	double input1, input2;
/*Opening Statement*/
	printf("\tCSCE 1030\n\tProgram #2\n\tColby Holmes\n\tCAH0448\n\tcolbyholmes@my.unt.edu\n\n");
	printf("-----Welcome to the Simple Calculator Program!-----\n\n\t1. Addition\n\t2. Multiplication"
		"\n\t3. Square Root\n\t4. Exit\n\nPlease select an option: ");
/*Loop to allow reuse of program*/	
	while(choose != 4)
	{
		scanf("%d", &choose);

/*Loop to confirm legal value*/	
		while (choose < 1 || choose > 4)
		{
			printf("\nI'm sorry. The number you entered does not match an option. Please enter a "	
				"number between 1 and 4: ");
			scanf("%d", &choose);
		}

/*Controls which option to use. ***I used a switch statement for convenience (Professor said it was okay.)*/	
		switch(choose)
		{
			case 1:
			{
			printf("\n\n-----Addition-----\n\nPlease enter the 2 numbers you wish to add together: ");
			scanf("%lf %lf", &input1, &input2);
			printf("The value of the two added is: %f\n", input1 + input2);		
			break;
			}

			case 2:
			{
			printf("\n\n-----Multiplication-----\n\nPlease enter the 2 numbers to be multiplied: ");
			scanf("%lf %lf", &input1, &input2);
			printf("The value of the two multipied is: %f\n", input1 * input2);
			break;
			}
	
			case 3:
			{
			printf("\n\n-----Square Root-----\n\nPlease enter the number to be square rooted: ");
			scanf("%lf", &input1);
			printf("The square root of the number is: %f\n", sqrt(input1));
			break;
			}	
/*This case ends the program.*/	
			case 4:
			{
			printf("Thanks for using the Simple Calculator Program!\n");
			exit(0);
			}
		}
/*Asks to select another option when the first has executed fully.*/		
		printf("Please choose another option: ");
	}
/*End of program.*/
	return 0;
}
