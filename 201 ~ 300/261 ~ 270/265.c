#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int push(int value);
int pop(int *value);

#define STACK_MAX 100

typedef struct tagStack
{
    int array[STACK_MAX];
    int top;
    int bottom;
}STACK;

STACK s;

void main(void)
{
    char buff[100], tmp[100];
    char *op = "+-*/%";
    int index;
    int value1 = 0, value2 = 0;

    s.top = STACK_MAX;

    puts("Enter the formula as 1 * 2 and press Enter.");
    puts("If you do not enter anything the calculation is terminated.");

    for(;;)
    {
        printf("formula :");
        gets(buff);

        if(strlen(buff) == 0) break;

        memset(tmp, 0, sizeof(tmp));

        index = strspn(buff, op);

        memcpy(tmp, buff, index);

        value1 = atoi(tmp);
        value1 = atoi(&buff[index+1]);

        switch(buff[index])
        {
            case '+' : value1   += value2;  break;
            case '-' : value1   -= value2;  break;
            case '*' : value1   *= value2;  break;
            case '/' : value1   /= value2;  break;
            case '%' : value1   %= value2;  break;
            default  :
                puts("잘못된 연산자를 사용하였습니다.");
                continue;
        }

        if(push(value1) == -1)
        {
            puts("더 이상 저장할 수 없습니다.");
        }

        printf("%s = &d, s.top = %d \n\n", buff, value1, s.top);
    }

    value1 = 0;

    for(;;)
    {
        if(pop(&value2) == -1) break;

        value1 += value2;
    }

    printf("계산의 총합은 %d입니다.\n", value1);
}

int push(int value)
{
    if(s.top == 0) return -1;
    s.array[--s.top] = value;
    return 0;
}

int pop(int *value)
{
    if(s.top == STACK_MAX) return -1;
    *value = s.array[s.top++];
    return;
}
