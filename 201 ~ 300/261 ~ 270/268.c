#include <stdio.h>
#include <malloc.h>
#include <string.h>

int add_list(char* name, char* tel, char* addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkedList
{
    char name[30];
    char tel [30];
    char addr[100];

    struct tagLinkedList *prev;
    struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

void main(void)
{
    add_list("Dad", "010-4803-1490", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu, age : 47");
    add_list("Mom", "010-3822-4835", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu, age : 43");
    add_list("Brother", "010-3521-1490", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu, age : 14");
    add_list("Me", "010-3586-1490", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu, age : 13");
    add_list("mollang", "???-????-????", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu, age : 3");
    add_list("mallang", "???-????-????", "Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu, age : 1");

    print_list();
    remove_list();
}

int add_list(char* name, char* tel, char*addr)
{
    ADDR *plocal;

    //g_pAddrHead가 초기화되지 않은 경우, 한 번만 실행됩니다.
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

    strcpy(g_pAddrHead->name, name);(g_pAddrHead->tel, tel);
    strcpy(g_pAddrHead->addr, addr);

    return 1;
}

void print_list(void)
{
    int count = 1;
    ADDR *plocal;

    plocal = g_pAddrHead;

    //plocal 리스트의 맨 처음으로 이동
    while(plocal->prev)
    {
        plocal = plocal->prev;
    }

    //한 개씩 출력
    while(plocal)
    {
        printf("No. %d\n", count++);
        puts(plocal->name);
        puts(plocal->tel );
        printf("%s \n\n", plocal->addr);

        plocal = plocal->next;
    }
}

void remove_list(void)
{
    ADDR *plocal;

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

    g_pAddrHead = NULL; //재사용을 하기 위한 초기화
}
