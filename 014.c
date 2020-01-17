#include <stdio.h>

main()
{
    int b;
    int j;

    b = 10 > 5;
    j = 10 > 20;

    printf("Of logical variable b %s\n",b);
    printf("Of logical variable j %s\n",j);

    if(b)   //참
    {
        printf("The expression 10> 5 is true. \n");
    }
    else
    {
        printf("The expression 10> 5 is false. \n");
    }

    if(j)   //거짓
    {
        printf("10> 20 is true.\n");
    }
    else
    {
        printf("10> 20 is false.\n");
    }

    if(-1)  //참
    {
        printf("-1 is true.\n");
    }
    else
    {
        printf("-1 is false.\n");
    }
}
