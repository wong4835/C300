#include <stdio.h>
#include <time.h>
#include <string.h>

void main(void)
{
    time_t now;
    struct tm t;
    char buff[100], AMPM[10];

    now = time(NULL);
    t = *localtime(&now);
    strftime(buff, sizeof(buff), "%y-%m-%d %H:%M:%S", &t);

    strftime(AMPM, sizeof(buff), "%P", &t);
    if  (strcmp(buff, "AM" ))strcpy(AMPM, "오전");
    else if  (strcmp(buff, "PM" ))strcpy(AMPM, "오후");
    strcat(buff, AMPM);

    puts(buff);
}
