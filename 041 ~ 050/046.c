#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

main()
{
    bool bCondition;

    bCondition = true;

    if(bCondition == true)
    {
        printf("조건식은 true입니다.");
    }
}
