#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    unsigned value;
    char string[100];
    int radix;

    radix = 16;

    value = 34567;
    itoa(value, string,radix);
    printf("변환된 문자열은 %s입니다.\n", string);

    value = 1234567890;
    itoa(value, string,radix);
    printf("변환된 문자열은 %s입니다.\n", string);
}
