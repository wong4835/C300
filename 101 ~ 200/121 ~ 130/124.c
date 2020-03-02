#include <stdio.h>
#include <string.h>

struct tagAddress
{
    char name[30];
    char phone[20];
    char address[100];
};

void print(struct tagAddress *pad);
void main(void)
{
    struct tagAddress ad[3];
    int i;

    for(i=0; i<3; i++)
    {
        sprintf(ad[i].name, "Kim tae woong %d", i);
        strcpy(ad[i].phone, "010-3586-1490");
        strcpy(ad[i].address, "473, Maegok-ri, Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu");
    }


    print(ad);
}

void print(struct tagAddress *pad)
{
    int i;

    for(i=0; i<3; i++)
    {
        printf("name : %s\n", pad[i].name);
        printf("phone : %s\n", pad[i].phone);
        printf("address : %s\n", pad[i].address);
    }
}
