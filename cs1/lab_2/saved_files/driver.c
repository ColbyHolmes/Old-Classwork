#include <stdio.h>
#include <stdlib.h>


// Your chore is to write MYstrcpy and MYstrlen

char *MYstrcpy(char *desination, char *source)
{
    return NULL;
}

int MYstrlen(char *source)
{
   return 0;
}
int main( int argc,  char *argv[] )
{
    // Let's do some string manipulation

    int index;
    char c, buffer[80];
    char *stringPtr, *literal = "This is a literal string";

    printf("Our string literal is %s, \nwhile the unititialized buffer is %s\n",
           literal, buffer); 
   printf("\n\n");
   // Ok, let's copy something into the buffer.

    MYstrcpy(buffer,literal);

    printf("Our string literal is %s, \nwhile the now ititialized buffer is %s\n",
           literal, buffer);
/*
   printf("\n\n");
   //OK, let's try stringPtr 

    MYstrcpy(stringPtr,literal);

    printf("Our string literal is %s, \nwhile the stringPtr is %s\n",
           literal, stringPtr);

    printf("\n\n");
*/




   //OK, let's try stringPtr that again 

    stringPtr = (char *) malloc(MYstrlen(literal));

    MYstrcpy(stringPtr,literal);

    printf("Our string literal is %s, \nwhile the stringPtr is %s\n",
           literal, stringPtr);

    printf("\n\n");

    // Now let's play some with buffer
    
    MYstrcpy(buffer+MYstrlen(buffer), literal);
    printf("Buffer is now %s\n", buffer);
    printf("\n\n");

    MYstrcpy(buffer,literal);
    printf("Buffer is now %s\n", buffer);
    printf("\n\n");

    index = MYstrlen(buffer) + 1;
    buffer[MYstrlen(buffer)] = ' ';
    MYstrcpy(buffer + index, literal);
    printf("Buffer is now %s\n", buffer);
    printf("\n\n");

}
