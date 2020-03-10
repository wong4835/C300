#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t;

    now = time(NULL);
    t = *localtime(&now);

    printf("현재 날짜 및 시간 : %s\n",
            asctime(&t));
}
