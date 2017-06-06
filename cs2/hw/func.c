/*Include header files*/
#include<stdio.h>
#include"structs.h"

/*function to add a course*/
void addCourse(int i, course* courses)
{
/*assign a course id # and set the # of students to 0*/
        courses[i].cID = 1000 + i;
	courses[i].students = 0;
/*Create a title for the course*/
        printf("Please enter the title of the course to be added: ");
        scanf(" %[^\n]s", (courses[i]).title);
/*Set the number of grades the course will have*/
	printf("How many grades will this class have (Max 10.): ");
	scanf("%d", &courses[i].nGrades);
	while (courses[i].nGrades > 10)
	{
		printf("The number of grades cannot exceed 10: ");
		scanf("%d", &courses[i].nGrades);
	}
/*Print the data*/
	printf("\n\n---Course Added---\nTitle: %s\nCID: %d\n# of Grades: %d\n", courses[i].title, courses[i].cID, courses[i].nGrades);
}

/*function to add a student*/
void addStudent(int i, student* students)
{
/*assign student id # and set the # of classes to 0*/
        students[i].sID = 100000 + i;
	students[i].classes = 0;
/*assign the student a name*/
        printf("Please enter the name of the student to be added: ");
        scanf(" %[^\n]s", (students[i]).name);
/*print data to screen*/
	printf("\n\n---Student Added---\nName: %s\nSID: %d\n", students[i].name, students[i].sID);
}

/*function to enroll a student in a course*/
void enroll(int sCount, int cCount, student* students, course* courses)
{
/*inportant variables*/
	int check, i, j;
/*scan in and check student id*/
	printf("Please enter the SID of the student you would like to enroll: ");
	scanf("%d", &check);
	for(i=0; i<=sCount; i++)
	{
		if(check == students[i].sID)
			break;
	}
	if(i > sCount)
		printf("***SID not found.\n\n");
	else if(students[i].classes >= 4)
		printf("***Sorry, this student is already enrolled in the max number of classes.\n\n");
/*if it is correct and the student doesnt have a full schedule follow the 'else'
Ask for a course id and check it in a similar fashion*/
	else
	{
		printf("Please enter the CID you would like to enroll %s to: ", students[i].name);
		scanf("%d", &check);
		for(j=0; j<=cCount; j++)
		{
			if(check == courses[j].cID)
				break;
		}
		if(j > cCount)
			printf("***CID not found.\n\n");
		else if(courses[j].students >= 20)
			printf("***Sorry, this class is already full.\n\n");
/*if the CID is valid and the class is not full proceed to enroll the student*/
		else
		{
			courses[j].students ++;
			students[i].enroll[students[i].classes].cID = check;
			students[i].enroll[students[i].classes].eID = students[i].sID + courses[j].cID;
			students[i].enroll[students[i].classes].nGrades = courses[j].nGrades;
			students[i].classes ++;
/*print the successful enrollment to the screen*/
			printf("\n\n---Enrollment Successful---\nStudent: %s\nCourse: %s\nEID: %d\n", students[i].name, courses[j].title,
				 students[i].enroll[students[i].classes -1].eID);
		}
	}
}

/*function to add a students grades for a course*/
void addGrades(int sCount, student* students)
{
        int check, i, j, k;
/*ask for the students id and course id and check them in a similar way explained in the enroll function*/
        printf("Please enter the SID of the student you would like to add grades for: ");
        scanf("%d", &check);
        for(i=0; i<=sCount; i++)
        {
                if(check == students[i].sID)
                        break;
        }
        if(i > sCount)
                printf("***SID not found.\n\n");
        else
        {
                printf("Please enter the CID for the class you would like to add %s's grades to: ", students[i].name);
                scanf("%d", &check);
                for(j=0; j<=students[i].classes; j++)
                {
                        if(check == students[i].enroll[j].cID)
                                break;
                }
                if(j > students[i].classes)
                        printf("***CID not found.\n\n");
                else
                {
/*if the SID and CID are valid collect user input grades for the class*/
                        printf("This class has %d grades. Please enter them now.\n", students[i].enroll[j].nGrades);
			for(k = 0; k < students[i].enroll[j].nGrades; k++)
			{
				printf("Grade %d: ", k+1);
				scanf("%d", &students[i].enroll[j].grades[k]);
			}
                }
        }
}

/*function to print a students grades in certain course*/
void printGrades(int sCount, student* students)
{
	int check, i, j, k;
/*check SID and CID in the similar way explained in the enroll function*/
        printf("Please enter the SID of the student you would like to print the grades of: ");
        scanf("%d", &check);
        for(i=0; i<=sCount; i++)
        {
                if(check == students[i].sID)
                        break;
        }
        if(i > sCount)
                printf("***SID not found.\n\n");
        else
        {
                printf("Please enter the CID of the class you would like to print %s's grades for: ", students[i].name);
                scanf("%d", &check);
                for(j=0; j<=students[i].classes; j++)
                {
                        if(check == students[i].enroll[j].cID)
                                break;
                }
                if(j > students[i].classes)
                        printf("***CID not found.\n\n");
                else
                {
/*if the SID and CID are valid print out the grades for the student*/
			printf("---Grades---\n");
                        for(k = 0; k < students[i].enroll[j].nGrades; k++)
                        {
                                printf("Grade %d: %d\n", k+1, students[i].enroll[j].grades[k]);
                        }
                }
        }
}

/*function to print the students enrolled in a certain course*/
void printStudents(int sCount, student* students)
{
        int check, i, j, k;
/*scan in an check the course id*/
        printf("Please enter the CID of the class you would like to print the students of: ");
        scanf("%d", &check);
	printf("---Students---\n");
        for(i=0; i<=sCount; i++)
        {
		for(j=0; j<=students[i].classes; j++)
		{
/*check each students enrollment and print their name if they are in the course*/
                	if(check == students[i].enroll[j].cID)
                        printf("%d: %s\n", i+1, students[i].name);
        	}
	}	
}

/*function to calculate a student's average in a course*/
void compAverage(int sCount, student* students)
{
        int check, i, j, k;
	float avg = 0;
/*scan in and check the SID given*/
        printf("Please enter the SID of the student you would like to print the average of: ");
        scanf("%d", &check);
        for(i=0; i<=sCount; i++)
        {
                if(check == students[i].sID)
                        break;
        }
        if(i > sCount)
                printf("***SID not found.\n\n");
/*scan and check a course number to compute the average for*/
        else
        {
                printf("Please enter the CID of the class you would like to print %s's average for: ", students[i].name);
                scanf("%d", &check);
                for(j=0; j<=students[i].classes; j++)
                {
                        if(check == students[i].enroll[j].cID)
                                break;
                }
                if(j > students[i].classes)
                        printf("***CID not found.\n\n");
/*if the student and course are valid add all the grades for that class together, then divide the total by the number of grades*/
                else
                {
                        for(k = 0; k < students[i].enroll[j].nGrades; k++)
                        {
                                avg += students[i].enroll[j].grades[k];
                        }
			avg = avg/students[i].enroll[j].nGrades;
/*print the result to the screen*/
			printf("%s's Average: %.2f\n", students[i].name, avg);
                }
        }
}

/*function to print all the students in the gradebook*/
void printAllS(int sCount, student* students)
{
	int i;
	printf("---All Students---\n");
/*cycle all the students and print their basic information*/
	for(i=0; i<sCount; i++)
	{
		printf("Name: %s\nSID: %d\n\n", students[i].name, students[i].sID);
	}
}

/*function to print all the courses in the gradebook*/
void printAllC(int cCount, course* courses)
{
	int i;
	printf("---All Courses---\n");
/*cycle all the courses and print the basic information*/
	for(i=0; i<cCount; i++)
	{
		printf("Title: %s\nCID: %d\n\n", courses[i].title, courses[i].cID);
	}
}

/*function to calculate a course grade average*/
void compCourse(int sCount, student* students)
{
        int check, i, j, k, count = 0;
        float sAvg = 0, cAvg = 0;
/*scan in a check a course id*/
        printf("Please enter the CID of the course you would like to print the average of: ");
        scanf("%d", &check);

	for(i=0; i<=sCount; i++)
        {
                for(j=0; j<=students[i].classes; j++)
                {
                        if(check == students[i].enroll[j].cID)
                        {	
/*if a student is enrolled, calculate their average first, then add it to the class total*/
				for(k = 0; k < students[i].enroll[j].nGrades; k++)
                        	{
                                	sAvg += students[i].enroll[j].grades[k];
                        	}
                        	sAvg = sAvg / students[i].enroll[j].nGrades;
				cAvg += sAvg;
				count ++;
			}

                }
        }
/*after the student average total is calculated divide it by the number of students in the course and print to the screen*/
	cAvg = cAvg / count;
	printf("The course average is: %.2f\n", cAvg);
}

/*function to save the gradebook*/
void storeBook(int sCount, int cCount, student* students, course* courses)
{
/*open the gradebook data file and store the student and course arrays and their counts*/
	FILE* out;
	out = fopen("gradebook.dat", "w");
	fseek(out, 0, SEEK_SET);
	fwrite(students, sizeof(student), 100, out);
	fwrite(courses, sizeof(course), 25, out);
	fprintf(out, "%d %d", sCount, cCount);
	fclose(out);
/*tell the user it saved the gradebook*/
	printf("Gradebook saved successfully!\n");
}

/*function to load the gradebook*/
void loadBook(int* sCount, int* cCount, student* students, course* courses)
{
/*open the file and return to the top, then read the data into their respective arrays*/
	FILE* in;
	in = fopen("gradebook.dat", "r");
	fseek(in, 0, SEEK_SET);
	fread(students, sizeof(student), 100, in);
	fread(courses, sizeof(course), 25, in);
	fscanf(in, "%d %d", sCount, cCount);
	fclose(in);
/*inform the user of a successful load*/
	printf("Gradebook loaded!");
}
