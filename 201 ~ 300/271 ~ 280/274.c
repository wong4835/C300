#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#define ADDRFILE    "c:\\addrlist.txt"

typedef struct tagLinkedList
{
    char name[30];
    char tel [30];
    char addr[100];

    struct tagLinkedList *prev;
    struct tagLinkedList *next;
} ADDR;

ADDR *g_pAddrHead = NULL;
ADDR *g_pFind;
int g_pSaved = 1;

void get_addrlist(void);
int add_list(const ADDR *addr);
int find_list(const char *name);
void SetHeadPosition(void);
void SetHeadPosition(void);

void Add_addr(void);
void Find_addr(void);
void Modify_addr(void);
void Delete_addr(void);
void Print_addr(void);
void Save_addr(void);
void remove_addr(void);

void main (void)
{
    int ch;

    get_addrlist();

    puts("address program Version 1.0");

    while(1)
    {
        printf("\n[1]Add[2]Find[3]Modify[4]Delete[5]Print[S]Save[Q]End");

        ch = getch();

        switch(ch)
        {
            case '1' :Add_addr(); break;
            case '2' :Find_addr(); break;
            case '3' :Modify_addr(); break;
            case '4' :Delete_addr(); break;
            case '5' :Print_addr(); break;
            case 's' :
            case 'S' :Save_addr(); break;
            case 'q' :
            case 'Q' :
            if(g_bSaved == 0)
            {
                printf("\n\nDo you want to save the changed address date (y/n)?");
                ch = getchar();
                if(ch == 'Y' || ch == 'y')Save_addr();
            }

            Remove_addr(); return;
        default :printf("\n\nClick 1~5 or S/Q.\n\n"); break;
        }
    }
}

void get_addrlist(void)
{
    ADDR addr;
    FILE *fp;

    fp = fopen(ADDRFILE, "rb");

    if(fp == NULL)
    {
        perror("file opening error");
        return;
    }

    while(!feof(fp))
    {
        fread(&addr, sizeof(ADDR), 1, fp);

        if(ferror(fp))
        {
            fclose(fp);
            perror("file reading error");
            return;
        }

        if(feof(fp))break;

        if(add_list(&addr) == 0)
        {
            printf("address date is not plus to the linked list\n");
        }
    }

    fclose(fp);
}

int add_list(const ADDR *addr)
{
    ADDR *plocal, *pn = g_pAddrHead;

    SetHeadPosition();

    //g_pAddrHead가 초기화되지 않은 경우, 한번만 실행됩니다.
    if(g_pAddrHead == NULL)
    {
        plocal = malloc(sizeof(ADDR));
        memset(plocal, 0, sizeof(ADDR));

        if(plocal == NULL)
        {
            return 0;
        }

        g_pAddrHead = plocal;
        g_pAddrHead->prev = NULL;
        g_pAddrHead->next = NULL;
    }
    else
    {
        plocal = malloc(sizeof(ADDR));
        memset(plocal, 0, sizeof(ADDR));

        if(plocal = NULL)
        {
            return 0;
        }

        while(pn->next)
        {
            pn = pn->next;
        }

        pn->next = plocal;
        plocal->prev = pn;
        plocal->next = NULL;
    }

    strcpy(plocal->name, addr->name);
    strcpy(plocal->tel, addr->tel);
    strcpy(plocal->addr, addr->addr);

    return 1;
}

void SetHeadPosition(void)
{
    if(g_pAddrHead == NULLL)return;

    while(g_pAddrHead->prev)
    {
        g_pAddrHead = g_pAddrHead->prev;
    }
}

void SetTailPosition(void)
{
    if(g_pAddrHead == NULL)return;

    while(g_pAddrHead->next)
    {
        g_pAddrHead = g_pAddrHead->next;
    }
}

int find_list(const char *name)
{
    ADDR *plocal;

    SetHeadPosition();

    plocal = g_pAddrHead;

    while(plocal)
    {
        if(strstr(plocal->name, name))
        {
            g_pFind = plocal;
            return 1;
        }
        plocal = plocal->next;
    }

    return 0;
}

void Add_addr(void)
{
    ADDR addr;

    memset(&addr, 0, sizeof(ADDR));

    printf("\n\n name to register :");gets(addr.name);

    if(strlen(addr.name)== 0)return;

    printf("call number to register");gets(addr.tel);
    printf("address to register");gets(addr.addr);

    if(find_list(addr.name) == 1)
    {
        printf("\nThis is the name you have already registered.\n\n");
        puts(g_pFind->name);
        puts(g_pFind->tel);
        puts(g_pFind->addr);
        return;
    }

    if(add_list(&addr))
    {
        g_bSaved = 0;
        printf("\nRegistered.\n\n");
    }
    else
    {
        printf("\nRegistration failed.\n\n");
    }
}

void Find_addr(void)
{
    char buff[100] = {0,};
    ADDR *plocal;

    printf("\n\nPlease enter part of the name / call number / addrss to search.\n");
    printf("name / call number :");gets(buff);

    if(strlen(buff) == 0)return;

    SetHeadPosition();

    plocal = g_pAddrHead;
    g_pFind = NULL;

    while(plocal)
    {
        if(strstr(plocal->name, buff)
        {
            g_pFind = plocal;
            break;
        }

        if(strstr(plocal->tel, buff))
        {
            g_pFind = plocal;
            break;
        }

        if(strstr(plocal->addr, buff))
        {
            g_pFind = plocal;
            break;
        }

        plocal = plocal->next;
    }

    if(g_pFind)
    {
        puts(g_pFind->name);
        puts(g_pFind->tel);
        puts(g_pFind->addr);
    }
    else
    {
        printf("\n\nWe can't find %s");
    }
}

void Modify_addr(void)
{
    char name[100] = {0,};
    ADDR addr;

    while(1)
    {
        printf("\n\nname to be modified :");gets(name);

        if(strlen(name) == 0)return;

        if(find_list(name) == 0)
        {
            puts("The name to be modified cannot be found.");
            continue;
        }
        break;
    }

    printf("\n%s is same for addrss data.\n\n", name);
    puts(g_pFind->name);
    puts(g_pFind->tel);
    puts(g_pFind->addr);

    printf("\nplease enter name to be modified name/call number/address and click enter\n\n");

    printf("name : "); gets(addr.name);
    printf("call number : "); gets(addr.tel);
    printf("address : "); gets(addr.addr);

    if(strlen(addr.name) == 0)strcpy(addr.name, name);

    strcpy(g_pFind->name, addr.name);
    strcpy(g_pFind->tel, addr.tel);
    strcpy(g_pFind->addr, addr.addr);

    g_bSaved = 0;

    printf("%s is modified to address data", name);
}

void Delete_addr(void)
{
    char name[100] = {0,};
    ADDR *plocal;
    int ch;

    while(1)
    {
        printf("\n\ndelete name :"); gets(name);

        if(strlen(name) == 0) return;

        if(find_list(name) == 0)
        {
            puts("We cannot find to delete name");
            continue;
        }
        break;
    }

    puts(g_pFind->name);
    puts(g_pFind->tel);
    puts(g_pFind->addr);

    printf("Delete the %s(y/n)?", name);
    ch = getch();
    fflush(stdin);

    if(ch == 'Y' || ch == 'y')
    {
        if(g_pFind->prev == NULL)
        {
            if(g_pFind->next == NULL)
            {
                free(g_pFind);
                g_pAddrHead = NULL;
            }
            else
            {
                plocal = g_pFind->next;
                free(g_pFind);
                plocal->prev = NULL;
                g_pAddrHead = plocal;
            }
        }

        else if(g_pFind->next == NULL)
        {
            plocal = g_pFind->prev;
            free(g_pFind);
            plocal->next = NULL;
            g_pAddrHead = plocal;
        }

        else
        {
            plocal = g_pFind->prev;
            plocal->next = g_pFind->next;

            plocal = g_pFind->next;
            plocal->prev = g_pFind->prev;

            free(g_pFind);
            g_pAddrHead = plocal;
        }

        g_bSaved = 0;

        printf("\n\n Delete the surch\n\n");
    }
}
