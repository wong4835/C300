#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void)
{
    char *pduf;

    pduf = malloc(100 * 10000);

    if(pduf)
    {
        memset(pduf, 0, 100 * 10000);
        strcpy(&pduf[0], "서울시 양천구 목동");
        puts(&pduf[0]);
        free(pduf);
    }
}
