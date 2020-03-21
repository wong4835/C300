#include <stdio.h>

void main(void)
{
    FILE *fpR, *fpW;
    char buff;
    int len;

    fpR = fopen("c:\\file.bin", "rb");

    if(fpR == NULL)
    {
        perror("파일 읽기 개방 에러");
        return;
    }

    fpW = fopen("c:\\file_copy.bin", "w+b");

    if(fpW == NULL)
    {
        perror("file gebang error");
        fclose(fpR);
        return;
    }

     while(!feof(fpR))
     {
        len = fread (&buff, 1, 1, fpR);
        if(ferror(fpR))
        {
            perror("file elgi error");
            fcloseall();
            return;
        }

        if(len > 0)
        {
            fwrite(&buff, 1, 1, fpW);
            if(ferror(fpW))
            {
                perror("file write error");
                fcloseall();
                return;
            }
        }
     }

     fcloseall();

     puts("The file was copied successfully.");
}
