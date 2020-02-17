#include <stdio.h>
#include <conio.h>

int print(char *string);

main()
{
    print("This is a putch function!");
}

int print(char *string)
{
    int len = 0;

    while( *string != (char)NULL)
    {
        putch( *string);
        string++;
        len++;
    }

    putch('\r');
    putch('\n');

    return len;
}
