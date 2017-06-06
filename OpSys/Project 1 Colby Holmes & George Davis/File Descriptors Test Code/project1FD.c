//File Descripters Test

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

pid_t B1;

int fork1(){
	FILE *fp;
	char buff[255];

//open file before forking
	fp = fopen("Project1.txt", "r");
   	fgets(buff, 255, (FILE*)fp);
	printf("\n\nTest Read: %s", buff );

//create child processes
	printf("\n\nProcesses Forked\n\n");
	B1 = fork ();
	
	if(B1==0){
//in child
//read the first line
   		fgets(buff, 255, (FILE*)fp);
		printf("Child File Pointer Memory Space: %p\n", fp);
        	printf("Child Read: %s\n", buff );
		
		exit(0);
	}
	else{
//in parent
//wait for child
		while(wait(NULL) !=-1){
			printf("Parent waiting on Child...\n");
		}

//read from same file, and print to compare
   		fgets(buff, 255, (FILE*)fp);
		printf("Parent File Pointer Memory Space: %p\n", fp);
        	printf("Parent Read: %s\n\n", buff );
	}

//close the file
	fclose(fp);

	return;
}

int main(){

	fork1();
	return 0;
}