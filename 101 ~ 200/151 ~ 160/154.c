#include <stdio.h>

void main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("c:\\file.txt", "r");

    if(fp == NULL)
    {
        puts("파일을 생성할 수 없습니다.");
    }
    else
    {
        while(!feof(fp))
        {
            ch = fgetc(fp);
            if(ferror(fp))
            {
                puts("파일을 읽는 중에 에러가 발생하였습니다.");
            }
            printf("읽은 문자 : %c\n", ch);
        }
        fclose(fp);
    }
}
