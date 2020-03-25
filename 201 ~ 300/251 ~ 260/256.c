#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t;
    char buff[100];

    now = time(NULL);
    t = *localtime(&now);
    strftime(buff, sizeof(buff), "올해의 경과된 주 : %u 주", &t);

    puts(buff);
}
