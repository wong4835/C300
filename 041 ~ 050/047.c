#include <stdio.h>

int print(char* string);

main()
{
    print("This is a function!");
}

int print(char* string)
{
    int len = 0;

    while(*string != (char)NULL)
    {
        printf("%c", *string);
        string++;
        len++;
    }

    return len;
}
