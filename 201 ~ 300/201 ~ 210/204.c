#include <stdio.h>

void main(void)
{
    int num;

    printf("Please enter a number : ");

    scanf("%d", &num);

    if(num % 2 == 1)printf("%d은 홀수입니다.\n", num);
    else printf("%d는 짝수입니다.\n", num);
}
