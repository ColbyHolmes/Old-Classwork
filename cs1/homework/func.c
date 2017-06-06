/*Colby Holmes
Mark Thompson
11/23/2014
Purpose: The purpose of this program is to create a working model of the classic game battleship.

Include Header files*/
#include "pgrm.h"

/*function definition ** This function places the ships on the board, preventing ships from running off the board or overlapping**/
int placeShip(char* board[SIZE], int length)
{
/*seed rand function*/
	srand(time(NULL));
/*declare variables*/
	int allign, row, col, i;
	allign = rand() % 2;
	row = rand() % 9;
	col = rand() % 9;
	char ship;
/*show which ship is being placed*/	
	if (length == CARRIER)
		ship = 'A';
	else if (length == BATTLE)
		ship = 'B';
/*makes sure the ship is on the board*/
	if ((allign == 0 && length + row > 9) || 
		(allign == 1 && length + col > 9))
	{
       		return 1;
	}

/*make sure the ships don't overlap*/
        for(i=0;i<length;i++)
        {
                if ((allign == 0 && board[row+i][col] != ' ') ||
			(allign == 1 && board[row][col+i] != ' '))
                {
                        return 1;
                }
   	}
/*if it passes the error checking, place the ship*/
	switch(allign)
	{
	case 0:
		for (i=0;i<length;i++)
		{
			board[row+i][col]= ship;
		}		
		break;
	case 1:
		for (i=0;i<length;i++)
		{
			board[row][col+i]= ship;
		}	
	}
	
	return 0;
}
/*function declaration ** This function prints the current board with the ships included*/
void printBoard(char* board[SIZE], int reveal)
{
	int i, j;
	printf("    1 2 3 4 5 6 7 8 9 10 \n"
		"  +---------------------+\n");
	for (i=0;i<SIZE;i++)
	{
		switch(i)
		{
		case 0:
			printf("A |");	
			break;
		case 1:
			printf("B |");
			break;
		case 2:
			printf("C |");
			break;
		case 3:
			printf("D |");
			break;
		case 4:
			printf("E |");
			break;
		case 5:
			printf("F |");
			break;
		case 6:
			printf("G |");
			break;
		case 7:
			printf("H |");
			break;
		case 8:
			printf("I |");
			break;
		case 9:
			printf("J |");
		}
		for(j=0;j<SIZE;j++)
		{
			if(reveal==0 && (board[i][j]=='A' ||
				 board[i][j]=='B'))
				printf("  ");
			else 
				printf(" %c", board[i][j]);
		}
		printf(" |\n");	
	}
	printf("  +---------------------+\n");
}
/*This function prints the header information*/
void header()
{
	printf("\tCSCE 1030.001\n\tProgram #6\n\tColby Holmes\n\t"
		"cah0448\n\tcolbyholmes@my.unt.edu\n\n");
}
/*This function prints the instructions for the user*/
void intro()
{
	printf("\t\t\tWelcome to BATTLESHIP!\n\nThe program will "
		"generate an aircraft carrier and a battle ship "
		"(lengths 5 and 4 respectively), on a 10x10 board."
		"You will then try to 'sink' these ships by guessing"
		" their locations. The number of guesses is based on "
		"the difficulty you choose:\n\tEasy = 30 Guesses\n\t"
		"Normal = 25 Guesses\n\tHard = 20 Guesses\n\n");
}

int shoot(char *board[SIZE], struct shotStatus *s)
{
	char check = board[((*s).row-65)][(*s).col-1];
	
	switch (check)
	{
	case ' ':
		printf("Shot missed...\n");
		board[((*s).row - 65)][(*s).col-1] = 'O';
		break;
	case 'A':
		printf("Direct Hit!\n");
		board[((*s).row - 65)][(*s).col-1] = 'X';
		(*s).airHit += 1;
		if ((*s).airHit == 5)
			printf("You sank the Aircraft Carrier!\n");
		break;
	case 'B':
		printf("Direct Hit!\n");
		board[((*s).row - 65)][(*s).col-1] = 'X';
		(*s).batHit += 1;
		if ((*s).batHit == 4)
			printf("You sank the Battleship!\n");
		break;
	case 'O':
	case 'X':
		printf("You already shot there!\n");
	}
		
	if ((*s).airHit == 5 && (*s).batHit == 4)
		return 1;
	else
		return 0;
}	
