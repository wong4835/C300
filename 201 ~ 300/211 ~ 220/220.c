#include <stdio.h>

void main(void)
{
    unsigned char *string = "대한민국 Korea";
    unsigned char buff[20]={0,};
    int i=0;

    while( *string)
    {
        if( *string)
        {
            buff[i++] = *string;
        }
        string++;
    }
    puts(buff);
}
