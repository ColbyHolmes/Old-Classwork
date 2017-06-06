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
    int x, y;

    x = 0;
    y = 0;

//creates a fork
    pid_t pid = fork();
//if it's the child process
    if (pid == 0)
    {    
	(void) increment(&x);
	printf("x = %d\n",x);    
    }
//if it's the parent
    else if (pid > 0)
    {    
	(void) increment(&y);
        waitpid(-1, NULL, 0);
	printf("y = %d\n",y);
    }
    else
    {
	printf("Error occurred during fork()");
    }
	
}
