/*Colby Holmes
11/8/2014
Mark Thompson
This program will create and populate a database for student grades and allow the user to access these grades in multiple ways

Include header files*/
#include<stdio.h>
#define SIZE 200

void menu(int*, float*, float*, float*, int);
int findStu(int*);
void stuAvg(int, float*, float*, float*);
void classAvg(float*, float*, float*, int);
/*Create main function*/
int main()
{
	printf("\tCSCE 1030\n\tHomework 5\n\tColby Holmes\n\t"
		"cah0448\n\tcolbyholmes@my.unt.edu\n\n");
	
/*Declare variables*/
	int id[SIZE], i, count = 0;
	float hwAvg[SIZE], exam1[SIZE], exam2[SIZE];
	
/*Scan in student data*/
	for (i=0;i<SIZE;i++)
	{
/*checks for end of file*/
		int checkID;
		scanf("%d", &checkID);
		if (checkID == EOF)
			break;
		else
/*scan in info if not end of data*/
		id[i] = checkID;
		scanf("%f %f %f", &hwAvg[i], &exam1[i], &exam2[i]);
		count++;
	}
/*Call menu*/
	menu(id, hwAvg, exam1, exam2, count);
/*End Program*/
	return 0;
}

/*Menu Function:
Lets the user choose what they would like to do with the data and calls functions from there*/
void menu(int* id, float* hw, float* ex1, float* ex2, int numStu)
{
        printf("\nPlease enter what information you want to view:\n"
                "1. Student Grade Data\n2. Student Grade Average\n"
                "3. Class Average for Assignment\n4. Exit\n>");
/*Declare variables and scan user choice*/
	int choice, refNum;
	scanf("%d", &choice);
/*checks for valid choice*/
	while (choice > 4 || choice < 1)
	{
		printf("\nPlease enter a valid option (1-4):");
		scanf("%d", &choice);
	}
/*Controls the menu options base on user input*/
	switch(choice)
	{
	case 1:
/*Student overview choice*/
/*calls findstu*/
		refNum = findStu(id);
/*Print Student info*/
		printf("EUID: %d\nHomework: %.2f\nExam 1: %.2f\n"
			"Exam 2: %.2f\n", id[refNum], hw[refNum],
			ex1[refNum], ex2[refNum]);
/*Loop back to menu*/
		menu(id, hw, ex1, ex2, numStu);
		break;
	case 2:
/*Student Avg choice*/
		refNum = findStu(id);
		printf("\nEUID: %d\n", id[refNum]);
/*call stuAvg*/
		stuAvg(refNum, hw, ex1, ex2);
/*loop menu*/
		menu(id, hw, ex1, ex2, numStu);
		break;
	case 3:
/*Call classAvg*/
		classAvg(hw, ex1, ex2, numStu);
/*loop menu*/
		menu(id, hw, ex1, ex2, numStu);		
		break;
	case 4:
/*Exit option*/
		return;
	}

}

/*findStu gets a reference number based on the EUID of the student so that grade data can be referenced easier*/
int findStu(int* id)
{
/*declare variables*/
	int i, idNum;
/*Ask for student id*/
	printf("\nPlease enter the student's EUID:");
	scanf("%d", &idNum);
/*Find student in array*/
	for (i=0;i<SIZE;i++)
	{
		if (id[i] == idNum)
/*return reference number*/
			return i;
	}
/*inform user and loop findstu if number isnt found*/
	printf("\n*Student Not Found*\n");
	findStu(id);
}

/*stuAvg averages the students grade and assigns them a letter grade*/
void stuAvg(int num, float* hw, float* ex1, float* ex2)
{
	char letter;
	float avg = ((hw[num] *.5) + (ex1[num] *.25) + (ex2[num] *.25));

	if (avg >= 89.5)
		letter = 'A';
	else if (avg >= 79.5)
		letter = 'B';
	else if (avg >= 69.5)
		letter = 'C';
	else if (avg >= 59.5)
		letter = 'D';
	else
		letter = 'F';

	printf("Grade Average: %.2f\nLetter Grade: %c\n", avg, letter);
}

/*classAvg asks for the user to pick an assignment and then tells them the average of the entire class ofr that assignment*/
void classAvg(float* hw, float* ex1, float* ex2, int numStu)
{
	printf("\nWhich assignment would you like the average for?\n"
		"'homework', 'exam1', or 'exam2'\n>");
	
	int i;
	float store = 0;
	char pick[10];
	scanf("%s", pick);
		
	if (strcmp(pick, "homework") == 0)
	{
		for (i=0; i<numStu; i++)
		{
			store += hw[i];
		}
	}
	else if (strcmp(pick, "exam1") == 0)
	{
		for (i=0; i<numStu; i++)
		{
			store += ex1[i];
		}
	}
	else if (strcmp(pick, "exam2") == 0)
	{
		for (i=0; i<numStu; i++)
		{
			store += ex2[i];
		}
	}
	else
	{
		printf("\nNot a valid response.\n");
		classAvg(hw, ex1, ex2, numStu);
	}
	printf("\nClass Average for %s: %.2f", pick, (store / numStu));
}
