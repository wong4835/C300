#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char string1[] = "1010";
    char string2[] = "ff";
    char *stop;
    long value;

    value = strtol(string1, &stop, 2);
    printf("2진문자열 \"%s\"을 정수로 바꾸면 %d입니다.\n", string1, value);

    value = strtol(string2, &stop, 16);
    printf("16진문자열 \"%s\"을 정수로 바꾸면 %d입니다.\n", string2, value);
}
