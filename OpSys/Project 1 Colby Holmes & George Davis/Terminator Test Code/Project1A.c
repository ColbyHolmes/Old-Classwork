//project1 & question 4 Termination

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


pid_t A1, A2;

//child process 1
int fork1(){
	int fd = open("A1_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	
	//create child
	A1 = fork ();

	//printing child and parent PID before sleep
printf(" Child A1 pid = %d, ppid=%d\n", (int)getpid(), (int)getppid());
	if(A1==0){

//parent waits for 3 seconds and terminates creating orphan, child adopted by init with ppid = 1
		sleep(3);
		dup2(fd, 1);
		execl("/bin/ls", "ls", "-l", (char *)0); 
printf(" After sleep Child A1 pid = %d, ppid=%d\n", (int)getpid(), (int)getppid());
	}
	
	close(fd);
}


//child process 2
int fork2(){
	int fd = open("A2_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	//create second child
	A2= fork ();

	//printing child and parent PID before sleep
printf(" Child A2 pid = %d, ppid=%d\n", (int)getpid(), (int)getppid());

	if(A2==0){

//parent waits for 3 seconds and terminates creating orphan, child adopted by init with ppid = 1
		sleep(3);
printf(" After sleep Child A2 pid = %d, ppid=%d\n", (int)getpid(), (int)getppid());
		dup2(fd, 1);
		execl("/bin/ps", "ps", "-ael", (char *)0);
	}
	close(fd);
}

int main(){
	//printf("Parent A ID is %d\n", (int) getppid());
	fork1();
	fork2();
	return 0;
}

