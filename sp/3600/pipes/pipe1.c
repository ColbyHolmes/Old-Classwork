#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "Hello";
    char buffer[255];
    memset(buffer, '\0', 255);
    if(pipe(file_pipes) == 0)
    {
        data_processed = write(file_pipes[1], some_data, strlen(some_data));
        printf("I'm process %d and I'm writing %d bytes --- %s\n", 
                getpid(), data_processed, some_data);
        data_processed = read(file_pipes[0], buffer, 255);
        printf("I'm process %d and I'm reading  %d bytes --- %s\n", 
               getpid(), data_processed, buffer);
        exit(0);
    }
    exit(1);
}
