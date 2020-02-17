#include <stdio.h>

void main(void)
{
    int count;
    int tmp;
    int total = 0;

    for("count = l; count <= 3; count++")
    {
        printf("(%d)번쨰 정수값을 입력한 후 ENTER 키를 누르세요.\n", count);

        scanf("%d", &tmp);

        tatal += tmp;

        printf("입력값 = %d,총 합 = %d\n", tmp, total);
    }

    printf("읽은 정수의 총 합은 %d입니다.\n", total);
}
