#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void)
{
    char date[] = "2005-06-23";
    time_t now;
    struct tm t = {0,};

    t.tm_mday = atoi(&date[8]);
    t.tm_mon  = atoi(&date[5]) -1;
    t.tm_year = atoi(&date[0]) -1900;

    now = mktime(&t);
    printf("2005-06-23을 time_t로 변환하면 %d입니다.\n", now);
}
