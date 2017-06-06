#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int main()
{
    int i,j;
    pid_t pid;

    for( i = 0; i < SIZE; i++ )
        {
    	    pid = fork();
	    if( pid == 0 )
	    {
	       printf("I'm process %d, and my parent is %d \n", 
		  getpid(), getppid());
               return 0;
	    }
            wait();
	}
	if( pid > 0)
        {
	    printf("I'm a papa process %d, and my parent is %d\n", 
		getpid(), getppid()); 
	}
	return 0;
}
