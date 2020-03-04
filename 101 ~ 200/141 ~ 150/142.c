#include <stdio.h>

void main(void)
{
    FILE *fp;
    int i;

    fp = fopen("c:\\file.txt", "r");

    if(fp == NULL)
    {
        puts("파일을 생성할 수 없습니다.");
    }
    else
    {
        fscanf(fp, "%d", &i);
        printf("i = %d\n", i);
        fclose(fp);
    }
}
