#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

pid_t B1;

int fork1(){
	int fd = open("B1_file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	B1 = fork ();
	if(B1!=0){
		printf("Parent B ID is %d\n", (int) getppid());
		printf("Child B1 ID is %d\n", (int) B1);
		int status = system("gcc Project1A.c");
		int status2 = system("./a.out");
		dup2(fd, 1);
		execl("/bin/date", "date", 0, (char*)0);
	}
	close(fd);
}

int main(){
	fork1();
}