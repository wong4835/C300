#include <stdio.h>

main()
{
    int i = 5;

    switch(i)
    {
    case 1:
        printf("i is 1.");
        break;
    case 2:
        printf("i is 2.");
        break;
    default:
        printf("i is %d.", i);
        break;
    }
}
