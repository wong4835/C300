#include <stdio.h>

#define     MAX(a,b)    a>b? a : b
#define     MIN(a,b)    a<b? a : b

main()
{
    int i, j;

    i = 5;
    j = 7;

    printf("최대값은 %d입니다.\n", MAX(i,j));
    printf("최소값은 %d입니다.\n", MIN(i,j));
}
