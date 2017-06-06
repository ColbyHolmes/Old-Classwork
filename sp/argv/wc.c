#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doThatArgThing(int, char *[]);

int main( int argc,  char *argv[] )
{
    doThatArgThing(argc, argv);
}

void doThatArgThing(int argc, char *argv[])
{
    int i;
    char *buffer;

    int bufferSize = 0;
    for( i = 0; i < argc; i++ )
	bufferSize += strlen(argv[i]) + 1;

    buffer = (char *)malloc(bufferSize);

    buffer[0] = '\0';
    strcpy(buffer,"wc ");

    for( i = 1; i < argc; i++ )
    {
	strcpy(buffer+strlen(buffer), argv[i]);
	strcpy(buffer+strlen(buffer), " ");
    }
   
    printf("buffer = %s\n", buffer);
    system (buffer);
}

// gcc -o mywc wc.c
