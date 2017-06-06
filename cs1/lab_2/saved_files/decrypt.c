#include <stdio.h>

int main()
{
    int i;
    char buffer[80];

    strcpy(buffer, "Irgv}txmsr$mw$jyr%");

    for(i = 0; i < strlen(buffer); i++)
	buffer[i] -= 4;

   printf("The code is      %s\n", buffer);

}
