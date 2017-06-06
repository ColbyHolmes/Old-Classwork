#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,roll, NUM =17;
    int counts[13];
    for(i = 0; i < 13; i++)
        counts[i] = 0;

    printf("Please enter the number of times you'd like to throw 2 dice\n");
    scanf("%d",&NUM);


    for(i = 0; i < NUM; i++)
    {
	    // random() generates a "random" value in the
            // range of 0 .. maxInt

            // two dice, each with values from 0..5

        roll = (random() % 6) + (random() % 6) + 2;
        counts[roll]++;
    }
    for(i = 2; i < 13; i++)
        printf("%d throws yielded %d rolls of %d\n",NUM,counts[i],i);
}

