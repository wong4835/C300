#include <stdio.h>

main()
{
    int i;
    int j;

    for(i = 1; i <= 1000; i++)
    {
        for(j = 1; j <= 1000; j++)
        {
            printf("%d * %d = %2d\n", i, j, i * j);
            if(i == 1000 && j == 1000)goto ku_ku_end;
        }
    }

ku_ku_end: ;
}
