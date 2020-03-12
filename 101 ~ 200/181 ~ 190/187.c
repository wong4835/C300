#include <stdio.h>
#include <math.h>

void main(void)
{

    double x = 2.3, n, y;

    y = modf(x, &n);

    printf("2.3을 정수와 소수로 분리하면,%g와 %g입니다.\n", n, y);
}
