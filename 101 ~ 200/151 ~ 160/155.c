#include <stdio.h>

void main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("c:\\file.txt", "r");

    if(fp == NULL)
    {
        perror("파일 개방 에러");
    }
    else
    {
        ch = fgetc(fp);
        if(ferror(fp));
        {
            perror("파일 읽기 에러");
        }
        fclose(fp);
    }
}
