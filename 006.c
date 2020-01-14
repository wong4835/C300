#include <stdio.h>

main()
{
    int i;
    int hap = 0;

    for(i = 1; i <= 10; i = i + 1)
    {
        hap = hap + i;
    }

    printf("sum from 1 to 10 : %d",hap );
}
