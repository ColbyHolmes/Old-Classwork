#include <stdio.h> 

#define N 40

static int A[N];
void permute(int num)
{
    int i;
    if( num == N-1 )
    {
        for( i = 0; i < N; i++ )
	    printf("%d ",A[i]);
	printf("\n");
    }
    else
    {
        int j, temp;
        for( j = num; j < N; j++ )
        {
	    temp = A[num]; A[num] = A[j]; A[j] = temp;
            permute(num+1);
	    temp = A[num]; A[num] = A[j]; A[j] = temp;
        }
    }
}


int main()
{
    int i;
    for( i = 0; i < N; i++ )
        A[i] = i+1;
    permute(0);  
}
