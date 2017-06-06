/*Colby Holmes
Lab 3 Tutorial*/

#include <stdio.h>
#include <stdlib.h>
#define HIGHEST 1000
#define LOWEST 1

int main(void)
{
	unsigned int number;
	
	srand((unsigned int) time(NULL));
	number = random()% (HIGHEST -LOWEST +1) +LOWEST;
	printf("Random number: %d\n", number);
	number  = random()% (HIGHEST -LOWEST +1) +LOWEST;
	printf("Random number: %d\n", number);
	number  = random()% (HIGHEST -LOWEST +1) +LOWEST;
	printf("Random number: %d\n", number);
        return 0;
}


