#include <stdio.h>

main()
{
    int i = 1;
    int hap = 0;

    while(i <= 10)
    {
        hap = hap + i;
        i++;
    }

    printf("hap = %d ", hap);
}
