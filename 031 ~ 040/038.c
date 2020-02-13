#include <stdio.h>

#define     ASCII_BEGIN         0
#define     ASCII_END           255

main()
{
    int i;

    for(i = ASCII_BEGIN; i <= ASCII_END; i++)
    {
        printf("ASCII cord (%3d), text = '%c'\n", i, i);
    }
}
