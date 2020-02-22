#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char *string = "0xFF";
    char *stop;
    int radix;
    long value;

    radix = 16;

    value = strtol(string, &stop, radix);

    printf("%d 개의 문자가 변환되였습니다.\n", stop - string);
    printf("16진수 %s를 숫자로 변환하면 %ld입니다.\n", string, value);
}
