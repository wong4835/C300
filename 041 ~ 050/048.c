#include <stdio.h>
#include <conio.h>

main()
{
    int ch;

    printf("아무키나 누르세요...\n");

    ch = getch();

    printf("%c 키가 눌려졌습니다.", ch);
}
