#include <stdio.h>

int main()
{
    int i;
    char *buffer;

    buffer = (char *) malloc(20);
    strcpy(buffer, "ET phone home!");

    for(i = 0; i < strlen(buffer); i++)
	buffer[i] += 4;

   printf("The code is      %s\n", buffer);
}
