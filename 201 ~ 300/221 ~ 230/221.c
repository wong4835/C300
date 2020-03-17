#include <stdio.h>
#include <string.h>

void main(void)
{
    char *string = "it's good";
    char *find = "abcdefghijklmnopqrstuvwxyz";
    int nIndex;

    nIndex = strspn(string, find);
    printf("Find the first non-alphabetic character at position %d.\n", nIndex);
}
