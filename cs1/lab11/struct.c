/*Colby Holmes
11/6/2014
Mark Thompson
Create a structure to be used by the program

Include header files*/
#include<stdio.h> 
/*create structure*/
struct employee
{ 
/* Fill this structure with the following information:
* -First Name
* -Last Name
* -Employee ID Number
* -Office Room Number
* -Office Phone Number
*/
	char fName[20], lName[20], phNum[14];
	int eID, rNum;
}; 

/*Call Main*/
int main() 
{ 
/*instanciate structure*/
	struct employee index; 
/* Prompt the user and read values associated with the 
above structure
After reading, print them out */
/*prompt user and read in inputs*/
	printf("Please enter the following data:\nFirst Name:");
	scanf("%s", index.fName);
	printf("\nLast name:");
	scanf("%s", index.lName);
	printf("\nEmployee ID Number:");
	scanf("%d", &index.eID);
	printf("\nOffice Room Number:");
	scanf("%d", &index.rNum);
	printf("\nOffice Phone Number:");
	scanf("%s", index.phNum);

/*print out user input*/
	printf("You entered the following data:\nName:\t\t%s %s\nID Number:\t%d\nRoom Number:\t%d\n"
		"Phone Number:\t%s\n", index.fName, index.lName, index.eID, index.rNum, index.phNum);

/*end program*/
	return 0;
}
