#include <stdio.h>
#include <stdlib.h>

void doThatArgThing(int argc, char *argv[]);

int main( int argc,  char *argv[] )
{
    doThatArgThing(argc, argv);
}

void doThatArgThing(int argc, char *argv[])
{
    int i;
    char *buffer;

    for( i = 0; i < argc; i++ )
    {
        printf("argument %i = %s\n", i, argv[i]);
    }

}

