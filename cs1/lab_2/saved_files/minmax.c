#include <stdio.h>

#define SIZE 1000
int Array[SIZE];
int main()
{
    int i;
    for(i = 0; i < SIZE; i++)
        Array[i] = random() % 25000 + 1;
    findMinMax();
    printf("The minimum value is %d\n", Array[0]);
    printf("The maximum value is %d\n", Array[SIZE-1]);
}


int findMinMax()
{
    int i, min = 25000, max = 0;
    int minIndex, maxIndex;
    for(i = 0; i < SIZE; i++)
    {
	if( Array[i] < min )
        {
	    min = Array[i];
            minIndex = i;
        }
	if( Array[i] > max )
        {
	    max = Array[i];
            maxIndex = i;
        }

    }
    swap(&(Array[minIndex]), Array);
    swap(Array + maxIndex, Array+SIZE-1);
}

int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}
