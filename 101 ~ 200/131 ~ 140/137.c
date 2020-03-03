#include <stdio.h>

void main(void)
{
    FILE *file;

    file = fopen("c:\\file.txt", "w+");

    if(file == NULL)
    {
        puts("파일을 생성할 수 없습니다.");
    }
    else
    {
        puts("파일이 정상적으로 생성되었습니다.");
        fclose(file);
    }
}
