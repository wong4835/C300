#include <stdio.h>

void main(void)
{
    char *filename = "c:\\file_1.txt";

    if(remove(filename))
    {
        perror("파일 삭제 에러");
    }
    else
    {
        puts("파일을 성공적으로 삭제하였습니다.");
    }
}
