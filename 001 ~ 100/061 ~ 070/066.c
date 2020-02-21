#include <stdio.h>
#include <string.h>

void main(void)
{
    char *string    = "This is a string $$$";
    char *strCharSet = "~!@#$%^&*()_+-={}[]:;'<>./?";
    unsigned int pos;

    pos = strcspn(string, strCharSet);

    puts("0   1   2   3");
    puts("0123456789012345678901234567890");
    puts("string");
    puts("strCharSet");

    printf("Found the first matching character at position% d.\n", pos);
}
