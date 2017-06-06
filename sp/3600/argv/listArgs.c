#include <stdio.h>

int main(int argc, char** argv)
{
    int i;
    printf("%s\n", argv[0] + 2);
    for( i = 1; i < argc; i++ )
    {
        printf("%s ", argv[i] );
    }
    printf("\n");
}
