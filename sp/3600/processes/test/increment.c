#include <stdio.h>
#include <stdlib.h>

int increment(int *num)
{
     int i;
     for(i = 0; i < 1000000000; i++)
          *num = *num + 1;
}


int main()
{
    int x,y;

    x = 0;
    y = 0;
    (void) increment(&x);
    (void) increment(&y);

    printf("x = %d\n",x);
    printf("y = %d\n",y);
}
