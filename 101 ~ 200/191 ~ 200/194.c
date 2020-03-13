#include <stdio.h>

#define x_i(x,i)printf("w%s의 값은 %d입니다.\n", #i, x##i)

void main(void)
{
    int xa = 3, xb = 5;

    x_i(x, a);
    x_i(x, b);
}
