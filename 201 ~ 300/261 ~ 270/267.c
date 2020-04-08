#include <stdio.h>
#include <malloc.h>
#include <string.h>

int add_list(char* name, char* tel, char* addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkedList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

void main(void)
{
    add_list("김석식", "1111", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu");
    add_list("김영욱", "2222", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu");
    add_list("김태원", "3333", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu");
    add_list("김태웅", "4444", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu");

    print_list();
    remove_list();
}

int add_list(char* name, char* tel, char* addr)
{
    ADDR *plocal, *pn = g_pAddrHead;

    if(g_pAddrHead == NULL)
    {
        g_pAddrHead = malloc(sizeof(ADDR));

        if(g_pAddrHead == NULL)
        {
            return 0;
        }

        g_pAddrHead->next = NULL;
        plocal = g_pAddrHead;
    }
    else
    {
        plocal = malloc(sizeof(ADDR));

        if(plocal == NULL)
        {
            return 0;
        }

        while(pn->next)
        {
            pn = pn->next;
        }

        pn->next = plocal;
        plocal->next = NULL;
    }

    strcpy(plocal->name, name);
    strcpy(plocal->tel, tel);
    strcpy(plocal->addr, addr);

    return 1;
}

void print_list(void)
{
    int count = 1;
    ADDR *plist;

    plist = g_pAddrHead;

    while(plist)
    {
        printf("No. %d\n\n", count++);
        puts(plist->name);
        puts(plist->tel);
        printf("%s\n\n", plist->addr);

        plist = plist->next;
    }
}

void remove_list(void)
{
    ADDR *plocal;

    while(g_pAddrHead)
    {
        plocal = g_pAddrHead->next;

        free(g_pAddrHead);

        g_pAddrHead = plocal;
    }
}
