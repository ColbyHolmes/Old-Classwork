/*Colby Holmes
CSCE1040
2/5/2015
Lab 2 Extra Credit*/

/*Include header files*/
#include <stdio.h>
#include <stdlib.h>

/*call main function*/
int main()
{
/*create necessary variables*/
	char **array;
	int xSize, ySize, i, j;

/*asks for dimensions to the 2d array*/
	printf("Please enter two integer values for the dimensions of the 2D array: ");
	scanf("%d %d", &xSize, &ySize);

/*dynamically allocates space based on user input*/
	array = ( malloc(xSize * sizeof(char *)));
	for (i=0; i<xSize; i++)
	{
		array[i] = ((char *) malloc(ySize * sizeof(char)));
	}

/*initializes the array spaces to ' '*/
	for (i=0; i<xSize; i++)
	{
		for (j=0; j<ySize; j++)
		{
			array[i][j] = ' ';
		}
	}

/*prints the size of the array*/
	printf("\nThe dimensions of the array are %d x %d.\n\n", xSize, ySize);

/*ends the program*/
	return 0;
}
