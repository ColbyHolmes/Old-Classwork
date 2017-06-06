/*Colby Holmes
Mark Thompson
11/23/2014
Purpose: The purpose of this program is to create a working model of the classic game battleship.

Include Header files*/
#include "pgrm.h"

/*Declare main()*/
int main()
{
/*Call header and instructions*/
	header();
	intro();
/*Declare variables*/
	char **board, diff[7];
	int i, j, check=1, guess=0, win=0;
	struct shotStatus shot;
	shot.airHit = 0;
	shot.batHit = 0;
/*Get user chosen difficulty*/
	while(guess == 0)
	{
		printf("Please choose a difficulty (easy, normal, or hard): ");
		scanf("%s", diff);

		if (strncmp(diff, "easy", 4) == 0)
			guess = 30;
		else if (strncmp(diff, "normal", 6) == 0)
			guess = 25;
		else if (strncmp(diff, "hard", 4) == 0)
			guess = 20;
		else
			printf("Unrecognized difficulty...\n\n");
	}
/*Create the board and initialize it*/	
	board = calloc(SIZE, sizeof(char*));
	for (i=0;i<SIZE;i++)
	{
		board[i] = calloc(SIZE, sizeof(char));
	}
	
	for (i=0;i<SIZE;i++)
	{
		for (j=0;j<SIZE;j++)
		{
			board[i][j] = ' ';
		}
	}

	printf("Initializing Board...(This may take a while.)\n\n");
/*Place the ships*/	
	while(check == 1)
	{
		check=placeShip(board, BATTLE);
	}	
	do{
		check=placeShip(board, CARRIER);
	}while(check == 1);

	i = 1;
	while (i<=guess && win == 0)
	{
		printBoard(board, 0);
		printf("Guess#: %d\nEnter Missile Coordinates: ", i);
		scanf(" %c", &shot.row);
		scanf("%d", &shot.col);;
		
		while ((shot.row < 'A' || shot.row > 'J') ||
			(shot.col < 1 || shot.col > 10))
		{
			printf("Please enter valid coordinates (A1 - J10): ");
			scanf(" %c", &shot.row);
			scanf("%d", &shot.col);;
		}

		win = shoot(board, &shot);
		i += 1;
	}
	if (win == 1)
		printf("**You sank both ships and WON!**\n");
	else
		printf("You ran out of missiles. Better luck next time.\n");
/*print the board with the ships*/
	printBoard(board, 1);
/*free allocated memory*/
	free(board);
/*end Program*/
	return 0;
}
	
