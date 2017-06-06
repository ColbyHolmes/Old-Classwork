/*Colby Holmes
CSCE 1040
Lab 9
4/2/2015*/
//include header files
#include <iostream>
#include <stdlib.h>
using namespace std;

//function prototypes
void printMat(int** matrix, int row, int col);
void sumEle(int** matrix, int row, int col);
void printUp(int** matrix, int row, int col);
void showMidR(int** matrix, int row, int col);
void showMidC(int** matrix, int row, int col);

//create main	
int main(int argc, char* argv[])
{
//declare and intialize vairables
	int row, col, count=0;
	row = atoi(argv[1]);
	col = atoi(argv[2]);
//allocate 2d array
	int** matrix = new int*[row];
	for (int i=0; i<row; i++)
	{
		matrix[i]= new int[col];
	}
//fill in matrix	
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			matrix[i][j] = atoi(argv[3 + count]);
			count++;
		}
	}	
//create option variable	
	int choice = 0;
//loop until end condition
	while (choice != 6)
	{
//ask for input
		cout << "Please choose an option:\n1. Print Matrix\n2.Sum all elements\n3. Show Upper Half\n"
	     	     << "4. Show Middle Row\n5. Show Middle Column\n6. Close program\nChoice: ";

		cin >> choice;
		
//check input validity
		while (choice > 6 || choice < 1)
		{
			cout << "Please choose an option between 1 and 6: ";
			cin >> choice;
		}
//switch for menu
		switch(choice)
		{
		case 1:
			printMat(matrix, row, col);
			break;
		case 2:
			sumEle(matrix, row, col);
			break;
		case 3:
			printUp(matrix, row, col);
			break;
		case 4:
			showMidR(matrix, row, col);
			break;
		case 5:
			showMidC(matrix, row, col);
			break;
		}
	}
	return 0;
}
//prints the matrix
void printMat(int** matrix, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
//calcs total of matrix
void sumEle(int** matrix, int row, int col)
{
	int total=0;
	for(int i=0; i<row; i++)
        {
                for(int j=0; j<col; j++)
                {
                        total += matrix[i][j];
                }
        }
	cout << "Total: " << total << endl;
}
//prints the upper half of the matrix if its a square
void printUp(int** matrix, int row, int col)
{
	if (row == col)
	{
        	for(int i=0; i<row; i++)
        	{
                	for(int j=0; j<col; j++)
                	{
				if(i > row/2)
				{
					cout << " ";
					continue;
				}
				else
                        		cout << matrix[i][j] << " ";
                	}	
                	cout << endl;
        	}
	}
	else
		cout << "Matrix is not a square." << endl;
}

//shows the middle row of the matrix if there is one
void showMidR(int** matrix, int row, int col)
{
	if(row %2 == 0)
	{
		cout << "Matrix does not contain a middle row!" << endl;
	}
	else
	{
		int mid = row/2;
		for (int j = 0; j<col; j++)
		{
			cout << matrix[mid][j] << " ";
		}
		cout << endl;
	}
}

//shows the middle column of the matrix if there is one
void showMidC(int** matrix, int row, int col)
{
	if(col %2 == 0)
	{
		cout << "Matrix does not contain a middle column!" << endl;
	}
	else
	{
		int mid = col / 2;
		for (int i=0; i<row; i++)
		{
			cout << matrix[i][mid] << " ";
		}
		cout << endl;
	}
}
