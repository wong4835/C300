#include <stdio.h>

typedef union tag tagVariable
{
    int i;
    double d;
}VA;

void print(VA *pva);

void main(void)
{
    VA va;

    print(&va);
}

void print(VA *pva)
{
    pva-> = 5;

    printf("pva->i 공용체의 값 : %d\n", pva->i);

    pva->d = 3.14;

    printf("pva->d 공용체의 값 : %f\n", pva->d);
    printf("pva->i 공용체의 값 : %f\n", pva->i);
}
