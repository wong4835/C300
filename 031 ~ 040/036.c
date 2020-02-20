#include <stdio.h>

main()
{
    int i = 1;
    int hap = 0;

    do
    {
        hap = hap + i;
        i++;
    }while(i <= 10);

    printf("hap = %d", hap);
}
