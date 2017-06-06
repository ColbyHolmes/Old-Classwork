/*Colby Holmes
CSCE 1040
2/12/2015
Lab 3 Recursion*/

#include <stdio.h>
/*function prototype*/
int liarLiar(int n);

int main()
{
	int n, i;
	printf("Please enter a number between 1 and 23: ");
	scanf("%d", &n);
	while(n < 1 ||  n > 23)
	{
		printf("Enter a number between 1 and 23: ");
		scanf("%d", &n);
	}
	printf("123456789012345678901234567890\n");
	for(i=1; i<=n; i++)
	{
		printf("Liar-Liar(%2d) = %12d\n", i, liarLiar(i));
	}
	return 0;
}

int liarLiar(n)
{
	int temp;
	if (n == 2 || n == 1)
		return -1;
 	temp = 2* (liarLiar(n-1)+(liarLiar(n-2)));
	return temp; 
}
