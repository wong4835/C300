#include <stdio.h>
#include <string.h>

#define FIND_CHAR       'h'

void main(void)
{
    char string[100];
    char *ret;

    puts("If sky is included in the string, the program exits.");
    puts("If the string contains 'h', the program exits.");

    do
    {
        gets(string);

        ret = strchr(string, FIND_CHAR);

        if(ret != NULL)
        {
            puts("There is no 'h' in the string.");
        }
        else
        {
            printf("The 'h' string was found at the location of %d.", ret - string);
            break;
        }

    }while(1);
}
