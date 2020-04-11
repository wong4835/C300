#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct tagLinkedList
{
    char name[30];
    char tel[30];
    char addr[100];

    struct tagLinkedList *prev;
    struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

int add_list(ADDR *addr);
void print_list(void);
void remove_list(void);

void main(void)
{
    ADDR addr;

    puts("Please enter your address data to be added.");
    puts("To end the program, please press the Enter key.");

    while(1)
    {
        memset(&addr, 0, sizeof(ADDR));

        printf("name :");gets(addr.name);

        if(strlen(addr.name) == 0)break;

        printf("call number : "); gets(addr.tel);
        printf("address : "); gets(addr.addr);

        if(add_list(&addr))
        {
            printf("\naddress plus of data\n\n");
        }
    }

    print_list();
    remove_list();
}

int add_list(ADDR *addr)
{
    ADDR *plocal;
    FILE *fp;

    fp = fopen("c:\\addrlist.txt", "a+b");
    if(fp == NULL)
    {
        perror("error of file open");
        return 0;
    }

    // g_pAddrHead가 초기화되지 않은 경우, 한 번만 실행됩니다.
    if(g_pAddrHead == NULL)
    {
        g_pAddrHead = malloc(sizeof(ADDR));

        if(g_pAddrHead == NULL)
        {
            return 0;
        }

        g_pAddrHead->prev = NULL;
        g_pAddrHead->next = NULL;
    }
    else
    {
        plocal = malloc(sizeof(ADDR));

        if(plocal == NULL)
        {
            return 0;
        }

        g_pAddrHead->next = plocal;
        plocal->prev = g_pAddrHead;
        g_pAddrHead = plocal;
        g_pAddrHead->next = NULL;
    }

    strcpy(g_pAddrHead->name, addr->name);
    strcpy(g_pAddrHead->tel, addr->tel);
    strcpy(g_pAddrHead->addr, addr->addr);

    fwrite(addr, 1, sizeof(ADDR), fp);

    fclose(fp);

    return 1;
}

void print_list(void)
{
    int count = 1;
    ADDR *plocal;

    if(g_pAddrHead == NULL)return;

    plocal = g_pAddrHead;

    // plocal 리스트의 맨 처음으로 이동
    while(plocal->prev)
    {
        plocal = plocal->prev;
    }

    //한 개씩 출력
    while(plocal)
    {
        printf("No. %d\n", count++);
        puts(plocal->name);
        puts(plocal->tel);
        printf("%s\n\n", plocal->addr);

        plocal = plocal->next;
    }
}

void remove_list(void)
{
    ADDR *plocal;

    if(g_pAddrHead == NULL)return;

    //PA를 리스트의 맨 처음으로 이동
    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }

    //한 개씩 메모리 해제
    while(g_pAddrHead)
    {
        plocal = g_pAddrHead->next;

        free(g_pAddrHead);

        g_pAddrHead = plocal;
    }

    g_pAddrHead == NULL;
}
