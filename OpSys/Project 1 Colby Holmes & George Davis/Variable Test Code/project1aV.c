//Variables Tests Modification

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

pid_t A1, A2;

//global v test
int GTEST = 0;

int main(){
//print parent
	printf("Parent A ID is %d\n", (int) getppid());

//local before fork
	char lTest1 = 'a';

	A1 = fork ();

//local after fork
	char lTest2 = 'y';

	//printf("A1 fork ID is %d\n", (int) getppid());
	if(A1!=0){
		printf("Child A1 ID is %d\n", (int) A1);
	}
	else{
		//A1 variable tests
		GTEST = 42;
		lTest1 = 'z';
		lTest2 = 'n';
		printf("\nA1 Global Variable: %d\nA1 Global Variable Location: %p"
			"\n\nA1 Local Variable 1: %c\nA1 Local Variable 1 Location: %p\n"
			"\nA1 Local Variable 2: %c\nA1 Local Variable 2 Location: %p\n\n",
			GTEST, &GTEST, lTest1, &lTest1, lTest2, &lTest2);
		//End A1 Var tests
	
		exit(0);
	}


//second child fork
	A2= fork ();

	if(A2 != 0){
		printf("Child A2 ID is %d\n", (int) A2);
	}
	else{
		//A2 Var tests
		printf("\nA2 Global Variable: %d\nA2 Global Variable Location: %p"
			"\n\nA2 Local Variable 1: %c\nA2 Local Variable 1 Location: %p\n"
			"\nA2 Local Variable 2: %c\nA2 Local Variable 2 Location: %p\n\n",
			GTEST, &GTEST, lTest1, &lTest1, lTest2, &lTest2);
		//End A2 Var tests

		exit(0);
	}

	return 0;
}
