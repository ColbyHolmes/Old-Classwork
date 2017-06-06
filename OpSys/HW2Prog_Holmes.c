//Colby Holmes
//HW2 Problem 4
//References :
//http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void  ChildProcess1(void);
void  ChildProcess2(void);

int main()
{
     pid_t  pid, ppid, wpid;
     int    i = 0;

     pid = fork();
     ppid = getppid();

     if (pid == 0) { //child 1
	  printf("Child 1 :: Process ID: %d\tParent ID: %d\n", pid, ppid);
          ChildProcess1();
     }
     else { // parent	  
	  pid = fork();
          ppid = getppid();

	  if (pid == 0) { //child 2
	      printf("Child 2 :: Process ID: %d\tParent ID: %d\n", pid, ppid);
              ChildProcess2();
	  }
	  else { //parent
	      printf("Parent :: Process ID: %d\tParent ID: %d\n", pid, ppid);
	      while ((wpid = wait(&i)) > 0){}//wait on all children
	  }
     }
}

void  ChildProcess1(void)
{
   int fd = open("P2_file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
   dup2(fd, 1);
   execl("/bin/ps", "ps", "-ael", (char *)0);
   close(fd);
}

void  ChildProcess2(void)
{
   int fd = open("P3_file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
   dup2(fd, 1);
   execl("/bin/ls", "ls", (char *)0);
   close(fd);
}