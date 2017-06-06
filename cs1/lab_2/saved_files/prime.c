#include <stdio.h>
#include <math.h>
#define NUM  1973 


int main()
{
    int i;
    for(i = 2; i < sqrt(NUM); i++)
    if( (NUM % i == 0) )
    {
	printf("NUM is  %d * %d and so it is not prime\n", i, NUM/i);
	return 0;
    }

    printf("%d IS prime\n",NUM);
    return 0;
}
