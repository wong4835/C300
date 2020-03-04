#include <stdio.h>

void main(void)
{
    FILE *fp;

    fp = fopen("c:\\file.txt", "w+");

    if(fp == NULL)
    {
        puts("파일을 생성할 수 없습니다.");
    }
    else
    {
        fputs("Korea", fp);
        fflush(fp);
        fclose(fp);
    }
}
