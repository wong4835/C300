#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

void main(void)
{
    struct _timeb tb;
    struct tm t;
    char buff[100];

    _ftime(&tb);

    t= *localtime(&tb.time);

    printf("%4d-4d-%d %d:%d:%d.%d\n",
        t.tm_year+1900, t.tm_mon+1, t.tm_mday,
        t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);

        printf(ctime(&tb.time));
        printf(asctime(&t));
        puts(_strdate(buff));
        puts(_strdate(buff));
        strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p (%a)", &t);
        puts(buff);
        strftime(buff, sizeof(buff), "%#Y-%#m-%#d %#H:%#M:%#S %p (%a)", &t);
        puts(buff);
        strftime(buff, sizeof(buff), "%c", &t);
        puts(buff);
        strftime(buff, sizeof(buff), "%x %X", &t);
        puts(buff);
        strftime(buff, sizeof(buff), "%#c", &t);
        puts(buff);
        strftime(buff, sizeof(buff), "%#x", &t);
        puts(buff);
}
