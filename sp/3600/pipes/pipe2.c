#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// this program uses a pipe to allow data written by a parent process to
// be read by the child process.


int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "Hello";
    char buffer[255];

    pid_t fork_result;

    memset(buffer, '\0', 255);
    
    if(pipe(file_pipes) == 0)
    {
        fork_result = fork();
        if( fork_result == -1 )
        {
            fprintf(stderr, "Fork failure");
            exit(1);
        }

        if( fork_result == 0 )
        {
            data_processed = read(file_pipes[0], buffer, 255);
            printf("Process %d read %d bytes --- %s\n", 
		getpid(),data_processed, buffer);
            exit(0);
        }
        else
        {
	    system("sleep 1");
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("Process %d wrote %d bytes --- %s\n", 
		getpid(), data_processed, some_data);
        }
    }
    exit(0);
}
