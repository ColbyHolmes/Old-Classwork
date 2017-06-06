/*Colby Holmes
CSCE 1040
David Keithly
1/29/2015
*/

/*Include necessary header files*/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"

/*define classStats structure*/
typedef struct classStats{
float mean, min, max, median;
char* name;
} classStats;

/*Declare main function*/
int main()
{
/*Declare variables*/
	classStats compSci2;
	student **stud;
	float temp=0;
	int i;
	char classname[9];

/*Dynamically alloc space part 1*/
	stud = (student**) malloc(19* sizeof(student*));

/*scan class name*/
	scanf("%s ", classname);

	for (i=0; i<19; i++)
	{
/*Dynamically allocate student part 2*/
		stud[i] = (student *) malloc (sizeof(student));

/*Scan in student data*/
		scanf("%[ \n\t]s %s %d %d %d", stud[i]->first, stud[i]->last, &stud[i]->exam1,
			 &stud[i]->exam2, &stud[i]->exam3);	

/*Calculate and store mean grade*/
		stud[i]->mean = ((stud[i]->exam1 + stud[i]->exam2 + stud[i]->exam3) / 3);
	}

/*Use bubble function to sort the students*/
	bubble(stud, 19);
	
/*intialize min and max for comparison*/
	compSci2.min = 100;
	compSci2.max = 0;

/*set class median*/
	compSci2.median = stud[10]->mean;

/*find mean, min and max*/
	for(i=0; i<19; i++)
	{
		temp += stud[i]->mean;
		if (stud[i]->mean < compSci2.min)
			compSci2.min = stud[i]->mean;
		else if (stud[i]->mean < compSci2.max)
			compSci2.max = stud[i]->mean;
	}

/*calc class mean*/
	compSci2.mean = temp / 19;

/*print intial data*/
	printf("123456789012345678901234567890123456789012345678901234567890\n%s MEAN:  %.2f "
		"MIN:  %.2f MAX:  %.2f MEDIAN:  %.2f\n", classname, compSci2.mean, compSci2.min, compSci2.max, compSci2.median);

	for (i=0; i<19; i++)
	{
		printf("%12s %10s  %.2f\n", (*stud[i]).first, (*stud[i]).last, (*stud[i]).mean);
	}
	
	free(stud);		
	
	return 0;
}

