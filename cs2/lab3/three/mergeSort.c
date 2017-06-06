#include <stdio.h>
#include <stdlib.h>

#define SIZE 50000	// number of integers to sort

void merge(int [], int, int, int);

void mergesort(int items[], int low, int high)
{
	int mid;

	// ENTER CODE HERE FOR MERGESORT

	return;
}

void merge(int items[], int low, int high, int mid)
{
	// ENTER CODE HERE FOR MERGING	

	return;
}

int ITEMS[SIZE];

int main(void)
{
	int n = SIZE;
	int i, j;

	srand ((unsigned int)time(NULL));
	for(i = 0; i < n; i++) {
		ITEMS[i] = random() % 1000000;
	}

	printf("\n\n\nThe unsorted array is:\n");
	for(i = 0; i < n/10; i++) {
		for(j = 0; j < 10; j++) {
			printf("%d ", ITEMS[i*10+j]);
		}
		printf("\n");
	}

	mergesort(ITEMS,0,SIZE-1);

	printf("\n\n\nThe sorted array is:\n");
	for(i = 0; i < n/10; i++) {
		for(j = 0; j < 10; j++) {
			printf("%d ", ITEMS[i*10+j]);
		}
		printf("\n");
	}

	return 0;
}

