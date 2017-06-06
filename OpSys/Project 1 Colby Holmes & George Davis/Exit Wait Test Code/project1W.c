//project 1 Exit/Wait Test

#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


pid_t A1, A2;


int fork1(){

	printf("Child A1 ID is %d\n", (int) A1);

}

int fork2(){
	
	printf("\nChild A2 ID is %d\n", (int) A2);

}

int main(){

//print the parent id
	printf("\nParent A ID is %d\n\n", (int) getppid());

//create first child
	A1 = fork ();

	if(A1 != 0){
//show child id
		fork1();
	}
	else{
//exit child
         	printf("Child A1 completed\n");
		exit(0);
	}
//create second child
	A2= fork ();

	if(A2 != 0){
		fork2();
	}
	else{
//exit child
         	printf("Child A2 completed\n\n");
		exit(0);
	}

//wait parent
	while(wait(NULL) != -1 || errno != ECHILD){}
	printf("Parent completed\n\n\n");

	return 0;
}
