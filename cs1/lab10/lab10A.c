/*Colby Holmes
10/30/2014
Mark Thompson
The purpose of this program is to demonstrate both pass by reference and pass by vlaue*/
/*Include header file*/
#include <stdio.h> 
/*Include function prototypes*/
double by_value_cubed(double);
void by_reference_cubed(double, double*);
/*Declare main function*/
int main() 
{ 
/*Variable declaration*/
	double value1, value2;
	double answer1, answer2;
	value1=3.3;
/* call by_value_cubed to compute the cube of value1 and 
store it in answer1 */
	answer1 = by_value_cubed(value1);

	value2=2.2;
/* call by_ref_cubed to compute the cube of value2 and 
store it in answer2 */
/*point to answer2 to store the value there*/
	double *val = &answer2;
	by_reference_cubed(value2, val);

/* complete the following printf statement */
	printf("Value1 cubed= %f\t Value2 cubed= %f\n", answer1, answer2);

/*end function*/
	return 0;
}

/*create function to cube by value and return*/
double by_value_cubed(double val)
{
	return (val*val*val);
}
/*create function to cube value and store in answer by reference*/
void by_reference_cubed(double val, double *store)
{
	*store = val * val * val;
	return;
}
