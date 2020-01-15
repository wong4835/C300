#include <stdio.h>

int hapf(int value);

main()
{
    printf("sum from 1 to 10 %d\n",hapf(10)  );
    printf("sum from 1 to 100 %d\n",hapf(100)  );
    printf("sum from 1 to 1000 %d\n",hapf(1000)  );
}

int hapf(int value)
{
    int i;
    int hap = 0;

    for(i = 1;i <= value;i =i + 1)
    {
        hap + hap + i;
    }

    return hap;
}
