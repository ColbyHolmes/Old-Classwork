/*Colby Holmes
Lab 3 Tutorial*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50000	// number of integers to sort

void merge(int [], int, int, int);

void mergesort(int items[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low+high)/2;
		mergesort(items, low, mid);
		mergesort(items, mid+1, high);
		merge(items, low, mid, high);
	}
	return;
}

void merge(int items[], int low, int high, int mid)
{
	int sorted[SIZE], i= low, j=mid+1, k=0;
	while (i < mid && j <= high)
	{
		if (items[i] < items[j])
		{
			sorted[k]=items[i];
			k += 1;
			j += 1;
		}
		else
		{
			sorted[k]=items[i];
			k += 1;
			i += 1;
		}
	}
	while (i <= mid)
	{
		sorted[k]=items[i];
		k += 1;
		i += 1;
	}
	while (j <= high)
	{
		sorted[k]=items[j];
		k += 1;
		j += 1;
	}

	for(i=0; i<k; i++)
	{
		items[i] = sorted[i];
	}	

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
		for(j = 0; j < 10; j++) 
		{
			printf("%d ", ITEMS[i*10+j]);
		}
		printf("\n");
	}
	
	return 0;
}

