/*Colby Holmes
Mark Thompson
11/23/2014
Purpose: The purpose of this program is to create a working model of the classic game battleship.

Include Header files*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*Define Constants*/
#define SIZE 10
#define CARRIER 5
#define BATTLE 4
/*Include function prototypes*/
void header();
void intro();
void printBoard(char* board[SIZE], int reveal);
int placeShip(char* board[SIZE],int length);

struct shotStatus
{
	char row;
	int col, airHit, batHit; 
};	
