#include <stdio.h>

main()
{
    int x = 5;
    int y = 2;

    if(x > 0 && x < 10)
    {
        printf("0 > x < 10\n");
    }

    if(x < 0||y == 2)
    {
        printf("x is smaller than 0 or y is 2.\n");
    }

    if(!(x>y))
    {
        printf("x is not bigger than y.\n");
    }
}
