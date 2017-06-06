#include <stdio.h>
#include <stdlib.h>


// Your chore is to write MYstrcpy and MYstrlen

char *MYstrcpy(char *destination, char *source)
{
    for(; *destination++ = *source++ ; ) ; // empty for loop
       // ops 2n  --- for n = string length
    return destination;  // 1 for the return
}

int MYstrlen(char *source)
{
    int i;
    char *s = source;
    for(; *source++ ;  ) ; // empty for loop
    return (source - s - 1) ;	
}



int main( int argc,  char *argv[] )
{
    // Let's do some string manipulation

    int index;
    char buffer[80];
    char *stringPtr, *literal = "This is a literal string";

   // Ok, let's copy something into the buffer.

    MYstrcpy(buffer,literal);

    printf("Our string literal is %s, \nwhile the now ititialized buffer is %s\n",
           literal, buffer);
   
    printf("\n\n");

    stringPtr = (char *) malloc(MYstrlen(literal)+1);

    MYstrcpy(stringPtr,literal);

    printf("Our string literal is %s, \nwhile the stringPtr is %s\n",
           literal, stringPtr);

    printf("\n\n");

    printf("literal string length is %d\n",MYstrlen(literal));
}
