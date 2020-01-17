#include <stdio.h>

#define     HUNDRED             100

const char  j = 10;

main()
{
    HUNDRED = 200;      //에러 발생
    j = 200;            //에러 발생

    printf("The value of the string constant HUNDRED is %d\n",HUNDRED);
    printf("The value of the string constant j is %d\n",j);
}
