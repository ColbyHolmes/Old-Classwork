/*Colby Holmes
CSCE1040
Lab 5 assignment
Encrypter decrypter program*/

/*Include headers and prototypes*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(FILE*, FILE*);
void decrypt(FILE*, FILE*);

/*Main function*/
int main(int argc, char* argv[])
{
/*Open files (i would have opened in functions but i was having issues with the file pointers and moved it here. Come to find out it was because i had if(read *=* NULL)... stupid mistake*/
	FILE* read;
	FILE* write;

        read = fopen(argv[2], "r");
        if (read == NULL)
        {
                printf("Error opening file!");
                exit(-1);
        }

        write = fopen(argv[3], "w");
        if (write == NULL)
        {
                printf("Error opening file!");
                exit(-1);
        }

/*check user input for correct command*/
	if (strcmp("encrypt", argv[1]) == 0)
	{
		encrypt(read, write);
	}


	else if (strcmp("decrypt", argv[1]) == 0)
	{
		decrypt(read, write);
	}
	else
		printf("Sorry the input command could not be verified.");	
/*closes the files*/
	fclose(read);
	fclose(write);

	return 0;
}

/*encryption function*/
void encrypt(FILE* in, FILE* out)
{
/*I also overcomplicated this because of the before-mentioned problem*/
        int i;
	/*finds the length of the file to read it in until EOF the hard way*/
	fseek(in, 0L, SEEK_END);
	int size = ftell(in);
	int store[size];
	fseek(in, 0L, SEEK_SET);
        
	for (i=0; i<size; i++)
	{
/*stores bit complement*/
		store[i] = ((int) (~(fgetc(in))));
	}
/*prints the output to the specified file*/
	for(i=0; i<size; i++)
	{
		fprintf(out, "%d ", store[i]);
	}
	
}

/*decrypt function (not overcomplicated)*/
void decrypt(FILE* in, FILE* out)
{
/*reads until end of file printing bit complement as it goes*/
        int c;
	fscanf(in, "%d ", &c);
	while(!feof (in))
	{
		fprintf(out, "%c", ~c);
		fscanf(in, "%d ", &c);
	}
}
