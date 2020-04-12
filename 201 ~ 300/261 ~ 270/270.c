#include <stdio.h>

#define ADDRFILE

typedef struct tagLinkedList
{
    char name[30];
    char tel [30];
    char addr[100];

    struct tagLinkedList *prev;
    struct tagLinkedList *next;
}ADDR;

void main(void)
{
    ADDR addr;
    FILE *fp;

    fp = fopen(ADDRFILE, "rb");

    if(fp == NULL)
    {
        perror("file gabang error");
        return;
    }

    while(!feof(fp))
    {
        fread(&addr, 1, sizeof(ADDR), fp);

        if(ferror(fp))
        {
            fclose(fp);
            perror("file ligi error");
            return;
        }

        if(feof(fp)) break;

        printf("name : %s\n", addr.name);
        printf("tel : %s\n", addr.tel);
        printf("adresss : %s\n", addr.addr);
    }

    fclose(fp);
}
