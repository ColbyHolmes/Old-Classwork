#include <stdio.h>
#include <stdlib.h>

#define NUM 10000

int main()
{
    int i,roll;
    int counts[13];
    for(i = 0; i < 13; i++)
        counts[i] = 0;

    for(i = 0; i < NUM; i++)
    {
            // Hapless Hap wants to shorten the following statement
            // while keeping the same values.

        roll = 2 * (random() % 6) + 2;
        counts[roll]++;
    }
    for(i = 2; i < 13; i++)
        printf("%d throws yielded %d rolls of %d\n",NUM,i, counts[i]);
}

