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
    struct tagAddress ad;

    strcpy(ad.name, "Kim tae woong");
    strcpy(ad.phone, "010-3586-1490");
    strcpy(ad.address, "473, Maegok-ri, Dasa-eup, 60, Dasa Station-ro, Dalseong-gun, Daegu");

    printf("name : %s\n", ad.name);
    printf("phone : %s\n", ad.phone);
    printf("address : %s\n", ad.address);
}
