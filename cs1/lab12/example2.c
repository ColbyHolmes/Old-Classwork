#include <stdio.h>

void setint(int*, int);

int main(void) 
{
    int a;
    setint(&a, 10);
    printf("a= %d\n",a);
    int b;
    setint(&b, 10);
    printf("b= %d\n",b);
    return 0;
}

void setint(int* ip, int i) 
{
    *ip = i;
} 
