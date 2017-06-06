#include <stdio.h>

#define SIZE 32

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
void randomize(int dim, int);
void compute_element(int, int);
void print();

int main()
{
	int i,j;
	// place random values in A and B
	randomize(SIZE,100);

	for( i = 0; i < SIZE; i++ )
	    for( j = 0; j < SIZE; j++ )
	        compute_element(i,j);
	print();
	return 0;
}

void randomize(int dim, int big)
{
	int i,j;
	for( i = 0; i < dim; i++ )
	   for( j = 0; j < dim; j++ ) {
		A[i][j] = random() % big;
		B[i][j] = random() % big; 
	   }
}

void compute_element(int iNum, int jNum)
{
	int sum = 0;
	int k;
	C[iNum][jNum] = 0;
	for( k = 0; k < SIZE; k++ )
           if( k % 2 )
	       C[iNum][jNum] += A[iNum][k] * B[k][jNum];
           else
	       C[iNum][jNum] -= A[iNum][k] * B[k][jNum];

}

void print()
{
	int i,j;
	for(i = 0; i < SIZE ; i++)
	    for(j = 0; j < SIZE ; j++)
		printf("C[%d][%d] = %d\n", i, j, C[i][j]);
}
