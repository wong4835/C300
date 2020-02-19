#include <stdio.h>

int count(char*str);

void main(void)
{
    char string[100];
    char*ret;

    ret = gets(string);

    if(ret != NULL)
    {
        printf("문자 'a'의 갯수는%d개입니다.", count(string));
    }
}

int count(char*str)
{
    int cnt = 0;

    while(*str != (int)NULL)
    {
        if(*str++ == 'a')cnt++;
    }

    return cnt;
}
