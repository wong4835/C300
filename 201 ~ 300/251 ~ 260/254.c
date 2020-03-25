#include <stdio.h>
#include <time.h>

void main(void)
{
    struct tm t1, t2,t3;
    int n1, n2, n3;

    t1.tm_year = 2005-1900;
    t1.tm_year = 6-1;
    t1.tm_year = 15;
    t1.tm_year = 1;
    t1.tm_year = 12;
    t1.tm_year = 50;

    t1.tm_year = 2005-1900;
    t1.tm_year = 8-1;
    t1.tm_year = 19;
    t1.tm_year = 3;
    t1.tm_year = 35;
    t1.tm_year = 22;

    n1 = mktime(&t1);
    n2 = mktime(&t2);

    n3 = n2 - n1;
    t3 = *gmtime (&n3);
    t3.tm_year -= 70;

    printf("day 1 : %4d-%4d %4d:%4d:%4d\n",
        t1.tm_year+1900, t1.tm-mon+1, t1.tm_mday,
        t1.tm_hour, t1.tm_min, t1.tm_sec);

        printf("day2 : %4d-%02d-%02d %02d:%02d:%02d\n",
            t2.tm_year+1900, t2.tm_mon+1, t2.tm_mday,
            t2.tm_hour, t2.tm_min, t2.tm_sec);

            printf("time difference : %4d-%02d-%02d %02d:%02d:%02d\n",
                t3.tm_year, t3.tm_mon, t3.tm_mday,
                t3.tm_hour, t3.tm_min, t3.tm_sec);
}
