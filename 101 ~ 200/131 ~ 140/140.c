#include <stdio.h>

void main(void)
{
    FILE *fp;
    char buffer[100];

    fp = fopen("c:\\file.txt", "r");

    if(fp == NULL)
    {
        puts("파일을 생성할 수 없습니다.");
    }
    else
    {
        fgets(buffer, 100, fp);
        puts(buffer);
        fclose(fp);
    }
}
