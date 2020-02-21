#include <stdio.h>

#define     HUNDRED_THOUSAND        100000

const int   j = 200000;

main()
{
    HUNDRED_THOUSAND = 100000;       //에러 발생
    j = 200000;                      //에러 발생

    printf("The value of the integer constant HUNDRED_THOUSAND is%d\n",HUNDRED_THOUSAND);
    printf("The value of the integer constant j is%d\n",j);
}
