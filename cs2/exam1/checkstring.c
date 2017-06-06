/*Colby Holmes
CSCE 1040
Lab Exam 1
3/26/2015*/

#include<stdio.h>
#include<stdlib.h>
void aCheck(char* line, int count);

int main()
{
/*create File pointers and set to data file*/
	FILE* in = NULL;
	in = fopen("string", "r");
/*create necessary variables*/
	char check, line[25];
	int i, count=0;	
/*read in first line*/
	fscanf(in, "%s", line);

/*loop through each line of the file

i was told we only needed to write code for the specific data file given, that is why this loop has an int value
otherwise you would just read to EOF*/	
	for(i=0; i<18; i++)
	{
/*check first letter validity*/
		if(line[0] == 'A')
		{
/*add to count the send to check next letter*/
			count ++;	
			aCheck(line, count);	
		}
		else
/*print invaid*/
			printf("INVALID %s\n", line);
/*read next line*/		
		fscanf(in, "%s", line);
	}
/*close the file*/	
	fclose(in);
/*exit the program*/
	return 0;
}

/*check function*/
void aCheck(char* line, int count)
{
/*if else if block to check validity

If valid, increment count and check the next part of the sequence otherwise print invalid

If the end is reach and it is still valid print that it is and the sequence*/
	if(line[count] == 'A')
	{
		count ++;
		aCheck(line, count);	
	}
	else if (line[count] == 'B' && line[count +1] == 'B')
	{
		count += 2;
		aCheck(line, count);
	}
	else if (line[count] == '\0')
	{
		printf("  VALID %s\n", line);
	}
	else
		printf("INVALID %s\n", line);
}
