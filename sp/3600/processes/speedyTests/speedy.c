#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#define SIZE 32
struct matrix
{
	int C[SIZE][SIZE];
}*c_ptr;

int A[SIZE][SIZE], B[SIZE][SIZE];
void randomize(int dim, int);
void compute_element(int, int);
void print();

int main()
{
	int shmid;
	int i,j,k;
	pid_t pid;
	shmid = shmget(IPC_PRIVATE, sizeof(int) * SIZE*SIZE, 0666 | IPC_CREAT);
	c_ptr = shmat(shmid, 0, 0);
	// place random values in A and B
	randomize(SIZE,100);
	for( k = 0; k < 8; k++ )
	{
 	    pid = fork();
	    if( pid == 0 )
            {
	        for( i = k * SIZE/8; i < (k+1)* SIZE/8; i++ )
		    {
			 for( j = 0; j < SIZE; j++ )
			 {
				compute_element(i,j);
			 }
		    }
		return 0;
	    }
        }
	// print();
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
	c_ptr->C[iNum][jNum] = 0;
	for( k = 0; k < SIZE; k++ )
        if( k % 2 )
	   c_ptr->C[iNum][jNum] += A[iNum][k] * B[k][jNum];
	else
	   c_ptr->C[iNum][jNum] -= A[iNum][k] * B[k][jNum];
}

void print()
{
	int i,j;
	for(i = 0; i < SIZE ; i++)
	    for(j = 0; j < SIZE ; j++)
		printf("C[%d][%d] = %d\n", i, j, c_ptr->C[i][j]);
}
