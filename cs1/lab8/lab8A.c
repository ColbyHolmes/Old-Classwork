/*Authot: Colby Holmes
Date: 10/16/2014
Instructor: Mark Thompson
Purpose: Figure out why this code does not execute properly (sq. int x) and fix it.

Example: calling a function -- why doesn't this work?

This function does not work because of scope and the pass style of the function. It never actually changes
the value of x within main().  

Include header file*/
#include <stdio.h> 

/*Function header****Changed return type to in******/
int square_it(int num); 

/*Main function call*/
int main(void) 
{ 
/*Declare variables*/
	int x;
/*Ask for and scan in user input*/
	printf("Enter an integer: "); 
	scanf("%d", &x);
/*Print x unaltered*/
	printf("main: x = %d\n", x);
/*Set x to function return of square_it******Code change here. Set x equal to square it.*********/ 
	x = square_it(x); 
/*print new value of x*/
	printf("main: x ^ 2 = %d\n", x);
/*end prigram*/ 
	return 0; 
} 

/*Function definition*****Changed return type to int*******/
int square_it(int num) 
{ 
/*Print num unaltered*/
	printf("square_it: num = %d\n", num); 
/*Square num*/
	num *= num; /* multiply num by itself */ 
/*print new num*/
	printf("square_it: num ^ 2 = %d\n", num);
/*return squared value*/ 
	return num; 
}
