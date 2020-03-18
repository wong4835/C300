#include <stdio.h>
#include <string.h>

void main(void)
{
    char string[] = "암호는 Korea입니다.";
    char *pstr;

    pstr = strstr(string, "Korea");
    if(pstr)
    {
        strnset(pstr, '*', 5);
    }
    puts(string);
}
