#include <stdio.h>

void main(void)
{
    FILE *fp;

    fp = fopen("c:\\file.txt", "w+");

    fputs("fclose() 함수", fp);
    fclose(fp);
}
