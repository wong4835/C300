#include <stdio.h>
#include <string.h>

void main(void)
{
    char *string    = "this is a very good!";
    char *strCharSet = "abcdefghijklmnopqrstuvwxyz";
    unsigned int pos;

    pos = strspn(string, strCharSet);

    puts("0     1     2     3");
    puts("01234567890123456789012345678901234567890");
    puts(string);
    puts(strCharSet);

    printf("%d 위치에서 일치되지 않는 문자를 발견하였습니다.\n", pos);
}
