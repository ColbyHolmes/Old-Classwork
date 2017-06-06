/*Colby Holmes
11/6/2014
Mark Thompson
Add 2 square matrixes

Include header files*/
#include<stdio.h>

/*call main function*/
int main()
{
/*Declare variables*/
	int n;
/*Scan in array size*/
	scanf("%d", &n);
	int mat1[n][n], mat2[n][n], i, j;

/*Use loops to scan in each element of the array*/
/*Rows*/
	for (i=0; i<n; i++)
	{
/*Columns*/
		for (j=0; j<3; j++)
			{
/*Scan in element*/
				scanf("%d", &mat1[i][j]);
			}
	}
        	

        for (i=0; i<n; i++)
        {
                for (j=0; j<3; j++)
                        {
                                scanf("%d", &mat2[i][j]);
                        }
        }

/*Use loops to print the array elements*/
	printf("First Matrix:");
	for (i=0; i<n; i++)
        {
		printf("\n");
                for (j=0; j<3; j++)
                        {
                                printf("%d ", mat1[i][j]);
                        }
        }
	
	printf("\n\nSecond Matrix:");
	for (i=0; i<n; i++)
        {
		printf("\n");
                for (j=0; j<3; j++)
                        {
                                printf("%d ", mat2[i][j]);
                        }
        }

/*Use loops again to print the elements added together*/
	printf("\n\nMatrix 1 + Matrix 2");		
        for (i=0; i<n; i++)
        {
                printf("\n");
                for (j=0; j<3; j++)
                        {
                                printf("%d ", mat1[i][j] + mat2[i][j]);
                        }
        }
	printf("\n");
/*end program*/
        return 0;
} 
