#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[] = "This is a book";
    char *pos;

    pos = strstr(string, "book");

    if(pos)
    {
        printf("book was found in %dth.\n", pos-string);
        printf("%s\n", &string[pos-string]);
    }
}
