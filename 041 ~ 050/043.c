#include <stdio.h>

struct tagSungJuk
{
    int kor;
    int eng;
    int math;
};

main()
{
    struct tagSungJuk SJ;

    SJ.kor = 100;
    SJ.eng = 95;
    SJ.math = 99;

    printf("총합 = %d", SJ.kor + SJ.eng + SJ.math);
}
