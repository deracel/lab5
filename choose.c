#include <stdio.h>
#include "lib.h"

char choose(){
    char variant;
    printf("a: Entering an array from the standard input stream\nb: Entering an array from a text file\nc: Entering an array from a binary file\n\n");
    printf("choose your variant: ");
    scanf("%c", &variant);
    return variant;
}