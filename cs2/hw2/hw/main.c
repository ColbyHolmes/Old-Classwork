/*Colby Holmes
CSCE 1040
Due 2/15/15
Homework 2*/

/*Include header files*/
#include<stdio.h>
#include<stdlib.h>
#include"structs.h"
#include"proto.h"

/*create main function*/
int main()
{
/*print assignment info*/
	printf("\n\n\tCSCE 1040\n\tHomework 2\n\tColby Holmes\n\tcolbyholmes@my.unt.edu\n\n");

/*create variables and structure arrays*/
	int choose = 0, cCount = 0, sCount = 0, cmax=chunk, smax=chunk;
	student* students= (student*) malloc(sizeof(student)*chunk);;
	course* courses= (course*) malloc(sizeof(course)*chunk);

/*print welcome message*/
	printf("-----Welcome to the Simple Grade Book!-----\n");

/*create program loop so it only closes on exit input*/
	while(choose != 13)
	{
/*print menu and scan in choice*/
		printf("\nPlease select an option:\n 1. Add a new course\n 2. Add a new student\n"
			" 3. Add a student to a course\n 4. Add grades for a student in a course\n 5. Print a student's grades for a course\n"
			" 6. Print a list of students in a course\n 7. Compute a student's average for a course\n 8. Print all course\n"
			" 9. Print all students\n 10. Compute course average\n 11. Save gradebook\n 12. Load gradebook\n 13. Exit program\n\nChoice: ");
		scanf("%d", &choose);
/*check for valid option*/
		while(choose < 1 || choose > 13)
		{
			printf("Please choose an option between 1 and 13: \n");
			scanf("%d", &choose);
		}

/*switch statement based on user input (calls all the functions)*/
		switch (choose)
		{
		case 1:
			if (cCount == cmax)
			{
				cmax += chunk;
				courses = (course*) realloc(courses, cmax);
			}
			addCourse(cCount, courses);
			cCount++;
			
			break;
		case 2:
			if (sCount == smax)
			{
				smax += chunk;
				students = (student*) realloc(students, smax);
			}	
			addStudent(sCount, students);
			sCount++;
			
			break;
		case 3:
			enroll(sCount, cCount, students, courses);	
			break;
		case 4:
			addGrades(sCount, students);
			break;
		case 5:
			printGrades(sCount, students);		
			break;
		case 6:
			printStudents(sCount, students);
			break;
		case 7:
			compAverage(sCount, students);					
			break;
		case 8:
			printAllC(cCount, courses);
			break;
		case 9:
			printAllS(sCount, students);
			break;
		case 10:
			compCourse(sCount, students);
			break;
		case 11:
			storeBook(sCount, cCount, students, courses);
			break;
		case 12:
			loadBook(&sCount, &cCount, students, courses);
			break;
		case 13:
			;
		}
	}
	free(students);
	free(courses);
/*exits the program*/
	return 0;
}

