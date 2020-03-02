#include <stdio.h>
#include <string.h>

void main(void)
{
    int(*myfunc[3])(const char*);

    myfunc[0] = puts;
    myfunc[1] = strlen;
    myfunc[2] = myfunc[1];

    puts("올챙이가 쑥 ~,~");
    myfunc("뒷다리가 쭉 ~,~");

    printf("문자열의 길이 : %d\n", strlen("aa"));
    printf("문자열의 길이 : %d\n", myfunc("aa"));
    printf("문자열의 길이 : %d\n", myfunc("aa"));
}
