#include <stdio.h>

#define max(x,y) x > y? x:y
#define min(x,y) x < y? x:y

void main(void)
{
    printf("최대 값 : %d\n", max(5,3));
    printf("최소 값 : %d\n", max(5,3));
    printf("최대 값 : %g\n", max(3.5, 4.4));
    printf("최소 값 : %g\n", max(3.5, 4.4));
}
