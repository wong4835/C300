#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[] = "3 lions, 5 elephants and 4 deer";
    char *find = "0123456789";
    int index;

    index = strcspn(string, find);

    printf("Found the first matching number at position% d.\n", index);
}
