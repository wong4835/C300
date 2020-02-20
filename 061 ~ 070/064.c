#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void)
{
    char string[100];
    char *ret;

    puts("Type in a string and press ENTER!");
    puts("If sky is included in the string, the program exits.");

    do
    {
        gets(string);

        ret = strstr(string, SKY);

        if(ret == NULL)
        {
            puts("There is no sky in the string.");
        }
        else
        {
            printf("The sky string was found at the location of %d.", ret - string);
            break;
        }

    }while(1);
}
