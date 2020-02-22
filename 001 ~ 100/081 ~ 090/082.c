#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char *string = "1.234E-10";
    char *stop;
    double value;

    value = strtod(string, &stop);

    printf("%d 개의 문자가 변환되였습니다.\n", stop - string);
    printf("16진수 [%s를 숫자로 변환하면 %E입니다.\n", string, value);
}
