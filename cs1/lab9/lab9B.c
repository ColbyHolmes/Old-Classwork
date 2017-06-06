/*Colby Holmes
10/23/2014
Mark Thompson
Play around with pointers setting them to different values and printing them*/
/*Include Header files*/
#include<stdio.h>

/*Declare main function*/
int main() 
{
	double d1, *p1, *p2;
/* Declare two pointers p1 and p2 to double */
	d1=10.0;
/* Set p1 to point to d1 */
	p1 = &d1;
/* Set p2 equal to p1 */
	p2 = p1;
/* Print d1, and the contents of p1 and p2. They should be the
 same! */
	printf("d1: %f\np1: %f\np2: %f\n", d1, *p1, *p2);
/* Set the contents of p2 to 33.33 */
	*p2 = 33.33;
/* Predict what will be the contents of p1 and the value of d1 */
	/************The contents of p1 and d1 should be the same as p2************/
/* Now print them all out as before. Was your prediction correct?********Yes.*********/
	printf("d1: %f\np1: %f\np2: %f\n", d1, *p1, *p2);
/* Do you understand why? ******Yes********/
	return 0; 
}

