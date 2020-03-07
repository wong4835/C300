#include <stdio.h>
#include <io.h>

void main(void)
{
    char *path = "c:\\file.txt";

    if(_access(path, 0) == 0)
    {
        puts("해당 경로의 파일이 존재합니다.");
    }
}
