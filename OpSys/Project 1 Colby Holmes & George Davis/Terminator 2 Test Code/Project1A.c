//project 1 & Terminator 2 question 5

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>


pid_t A1, A2;

//first child process
int fork1(){
	int fd = open("A1_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

	//child process created
	A1 = fork ();
	int A1pid = getpid();
	if(A1!=0){
		printf("Child A1 ID is %d\n", (int) A1);
		//child process terminated by parent
		kill  (A1pid,  SIGTERM);
		dup2(fd, 1);
		execl("/bin/ls", "ls", "-l", (char *)0); 
	}
	close(fd);
}

//second child process
int fork2(){
	int fd = open("A2_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	//child 2 created
	A2= fork ();
	if(A2 != 0){
		printf("Child A2 ID is %d\n", (int) A2);
		dup2(fd, 1);
		execl("/bin/ps", "ps", "-ael", (char *)0);
	}
	close(fd);
}

int main(){
	printf("Parent A ID is %d\n", (int) getppid());
	fork1();
	fork2();
}
