#include <stdio.h>
#include <time.h>

void main(void)
{
    time_t now;
    struct tm t, tb;

    now = time(NULL);
    t = *localtime(&now);

    tb = t;

    t.tm_mon += 100;
    t.tm_mday += 90;
    t.tm_hour += 80;

    mktime(&t);

    printf("to%d\n", );
}
