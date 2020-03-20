#include <stdio.h>

void main(void)
{
    char *filename = "c:\\file.txt";
    char *movefile = "c:\\temp\\file.txt";

    if(rename(filename, movefile)!= 0)
    {
        perror("file move error");
    }
    else
    {
        puts("file is move");
    }
}
