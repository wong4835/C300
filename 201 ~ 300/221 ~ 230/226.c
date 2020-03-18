#include <stdio.h>
#include <string.h>

void main(void)
{
    char buff[] = "암호는 Korea입니다.";

    puts(buff);
    strset(buff, 0);
    printf("[%s]\n", buff);
}
