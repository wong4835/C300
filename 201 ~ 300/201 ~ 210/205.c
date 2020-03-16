#include <stdio.h>

void main(void)
{
    int i, hap = 0;

    for(i=0; i<=100; i++)
    {
        if(i%2)
        {
            hap += i;
        }
    }

    printf("1~100까지의 홀수의 합 : %d\n", hap);
}
