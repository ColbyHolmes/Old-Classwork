#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doThatArgThing(int argc, char *argv[]);

int main( int argc,  char **argv )
{
    doThatArgThing(argc, argv);
}

void doThatArgThing(int argc, char **argv)
{
    int i;
    char buffer[80];
    for( i = 0; i < 80; i++ )
        buffer[i] = '\0';


    strcpy(buffer,argv[1]);
    for( i = 2; i < argc; i++ )
    {
	strcpy(buffer+(strlen(buffer)), " ");
	strcpy(buffer+strlen(buffer), argv[i]);
    }
    printf("Now buffer is: %s\n",buffer);
    // system(buffer);

}

