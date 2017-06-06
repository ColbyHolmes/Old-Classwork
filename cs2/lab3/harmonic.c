/*Colby Holmes
Lab 3 Tutorial 1*/

#include <stdio.h>
#include <stdlib.h>

float harmonic(int x, int base);

int main()
{
	int base = 0; // recursive base case
	float sum = 0; // sum of the generated series

//prompt for user base case
printf("Enter the number of terms to generate: ");
scanf("%d", &base);
//call the harmonic function
	//REMOVE LATER FOR FUNCTION CALL
//print the sum of the series
printf("sum: %f\n", sum);

return 0;
}

//function to determine the harmonic term
float harmonic(int x, int base)
{
	float sum = 0;
