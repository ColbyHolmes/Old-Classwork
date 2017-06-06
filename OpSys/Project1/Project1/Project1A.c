#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


pid_t A1, A2;


int fork1(){
	int fd = open("A1_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	A1 = fork ();
	//printf("A1 fork ID is %d\n", (int) getppid());
	if(A1!=0){
		printf("Child A1 ID is %d\n", (int) A1);
		dup2(fd, 1);
		execl("/bin/ls", "ls", "-l", (char *)0); 
	}
	close(fd);
}

int fork2(){
	int fd = open("A2_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
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
