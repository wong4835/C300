#include <stdio.h>

main()
{
    int i = 1;
    int j = 2;
    int k = 7;

    if(i == 1)
    {
        if(j == 2)
        {
            if(k == 3)
                printf("i = 1, j = 2, k = 3.");
            else if(k == 4)
                printf("i = 1, j = 2, k = 4.");
            else if(k == 5)
                printf("i = 1, j = 2, k =5.");
            else
                printf("i = 1, j = 2, k = %d.", k);
        }
    }
}
