#include <stdio.h>
#include <time.h>

void main(void)
{
    struct tm christmas = {0, 0, 0, 15, 8-1, 2020-1900};
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char buff[100];

    mktime(&christmas);

    strftime (buff, sizeof(buff), "December 25, 2007 is% A.", &christmas);

    puts(buff);
    printf("December25,2007is %sday.\n", wday[christmas.tm_wday]);
}
