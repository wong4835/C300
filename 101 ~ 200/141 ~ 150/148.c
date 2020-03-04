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
        fputs("abcde", fp);
        printf("파일 포인터의 위치 : %d\n", ftell(fp));
        fseek(fp, -2L, SEEK_CUR);
        printf("파일 포인터의 위치 : %d\n", ftell(fp));
        fclose(fp);
    }
}
