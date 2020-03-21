#include <stdio.h>

#define FILEREAD    4096

void main(void)
{
    FILE *fpR1, *fpR2, *fpW;
    char buff[FILEREAD];
    int len;

    fpR1 = fopen("c:\\file.bin", "rb");

    if(fpR1 == NULL)
    {
        perror("파일 읽기 개방 에러");
        return;
    }

    fpR2 = fopen("c:\\file.bin", "rb");

    if(fpR2 == NULL)
    {
        perror("파일 읽기 개방 에러");
        fcloseall();
        return;
    }

    fpW = fopen("c:\\file2.bin", "w+b");

    if(fpW == NULL)
    {
        perror("파일 쓰기 개방 에러");
        fcloseall();
        return;
    }

    while(!feof(fpR1))
    {
        len = fread (buff, 1, FILEREAD, fpR1);
        if(ferror(fpR1))
        {
            perror("파일 읽기 에러 1");
            fcloseall();
            return;
        }

        if(len > 0)
        {
            fwrite(buff, 1, len,fpW);
            if(ferror(fpW))
            {
                perror("파일 쓰기 에러 1");
                fcloseall();
                return;
            }
        }
    }

    while(!feof(fpR2))
    {
        len = fread (buff, 1, FILEREAD, fpR2);
        if(ferror(fpR2))
        {
            perror("파일 읽기 에러 2");
            fcloseall();
            return;
        }

        if(len > 0)
        {
            fwrite(buff, 1, len, fpW);
            if(ferror(fpW))
            {
                perror("파일 쓰기 에러 2");
                fcloseall();
                return;
            }
        }
    }

    fcloseall();

    puts("파일이 성공적으로 합쳐졌습니다.");
}
ㄴ
