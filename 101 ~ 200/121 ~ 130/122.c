#include <stdio.h>
#include <string.h>

struct tagAddress
{
    char name[30];
    char phone[20];
    char address[100];
};

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

    for(i=0; i<3; i++)
    {
        printf("name : %s\n", ad[i].name);
        printf("phone : %s\n", ad[i].phone);
        printf("address : %s\n", ad[i].address);
    }
}
