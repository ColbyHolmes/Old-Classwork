//Variable Tests Modification

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

pid_t B1;

//first test variable GLOBAL
int GTEST = 0;

int fork1(){
//2nd test variable local before fork
	char lTest1 = 'a';

	B1 = fork ();

//3rdd test variable local after fork
	char lTest2 = 'y';

	if(B1!=0){
		printf("Parent B ID is %d\n", (int) getppid());
		printf("Child B1 ID is %d\n", (int) B1);

		//B variable tests
		GTEST = 42;
		lTest1 = 'z';
		lTest2 = 'n';
		printf("\nB Global Variable: %d\nB Global Variable Location: %p"
			"\n\nB Local Variable 1: %c\nB Local Variable 1 Location: %p\n"
			"\nB Local Variable 2: %c\nB Local Variable 2 Location: %p\n\n",
			GTEST, &GTEST, lTest1, &lTest1, lTest2, &lTest2);
		//End B1 Var tests

		int status = system("gcc project1aV.c");
		int status2 = system("./a.out");
	}
	else{
		// B1 v tests
		printf("\nB1 Global Variable: %d\nB1 Global Variable Location: %p"
			"\n\nB1 Local Variable 1: %c\nB1 Local Variable Location 1: %p\n\n"
			"\nB1 Local Variable 2: %c\nB1 Local Variable 2 Location: %p\n\n\n\n",
			GTEST, &GTEST, lTest1, &lTest1, lTest2, &lTest2);
		//End B1 var Tests
	}

}

int main(){
	fork1();
}