/*Colby Holmes
CSCE 1040
Due 2/15/15
Homework 1*/

/*Include header files*/
#include<stdio.h>
#include"structs.h"
#include"proto.h"

/*create main function*/
int main()
{
/*print assignment info*/
	printf("\n\n\tCSCE 1040\n\tHomework 1\n\tColby Holmes\n\tcolbyholmes@my.unt.edu\n\n");

/*create variables and structure arrays*/
	int choose = 0, cCount = 0, sCount = 0;
	student students[100];
	course courses[25];

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
			if (cCount < 25)
			{
				addCourse(cCount, courses);
				cCount++;
			}
			else
				printf("Sorry, you have reached the max number of courses.");
			break;
		case 2:
			if (sCount < 100)
			{
				addStudent(sCount, students);
				sCount++;
			}
			else
				printf("Sorry, you have reached the max number of students.");
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
/*exits the program*/
	return 0;
}

