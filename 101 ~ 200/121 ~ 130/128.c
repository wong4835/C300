#include <stdio.h>

void main(void)
{
    int i;
    double d = 3.14;

    int *pi;
    double *pd;
    void *pv;

    pi = &i;
    pd = &d;
    pi = &d;
    pv = &i;
    pv = &d;

    printf("실수 값 d : %f\n", *(double*)pv);
}
