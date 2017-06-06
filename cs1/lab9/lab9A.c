/*Colby Holmes
10/23/2014
Mark Thompson
Fill the array with values and print them out in reverse order.*/

/*Include header files and define constants*/
#include<stdio.h>
#define SIZE 20

/*Create main function*/
int main() 
{
/*Declare variables (Array)*/
	float a[SIZE]; /* define SIZE to be 20 */
	int i;
 
/* Write a loop that fills the array values which are half of the 
index */
	for(i=0;i< SIZE;i++)
 		a[i] = i / 2.0;

/* Write a loop that prints the values of the given array
starting with the largest index down to index 0. Use the printf 
format of the working code example, i.e. print the index and the 
value */
	for(i=SIZE - 1; i >= 0; i--)
		printf("Array index %d, value %.2f\n", i, a[i]);

/*Ends Program*/
	return 0; 
}

