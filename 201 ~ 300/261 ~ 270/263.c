#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void check_game(int saram, int computer);

enum { GAWI=1, BAWI, BO};
enum { WIN=1, LOSE, TIE};

int point = 15000;

void main(void)
{
    int gamer, computer, cheat=0;
    int COM_gawi_bawi_bo[3] = {0,};
    int SRM_gawi_bawi_bo[3] = {0,};

    srand(time(NULL));

    puts("Start the Rock Paper Scissors game.");
    puts("Press the number and press the Enter key !!");

    for(;;)
    {
        printf("The computer issued scissors : %d times Rock : %d times Bo : %d times.\n",
            COM_gawi_bawi_bo[0], COM_gawi_bawi_bo[1], COM_gawi_bawi_bo[2]);

        printf("Gamer issued scissors : %d times Rock : %d times Bo : %d times.\n\n",
            SRM_gawi_bawi_bo[0], SRM_gawi_bawi_bo[1], SRM_gawi_bawi_bo[2]);

            computer = rand() % 3 + 1;
            if(cheat)printf("The computer gives %s.\n",
                computer == 1? "가위" : computer == 2? "바위":"보");

                printf("Current property : %d won \n Scissors (1) Rock (2) Beam (3) End (4) -->", point);

                scanf("%d", &gamer);

                if(gamer == 4)
                {
                    puts("Rock Paper Scissors will end the game ...");
                    return;
                }

                if(gamer == 9)
                {
                    puts("Use the Chitkey.");
                    cheat = 1;
                }

                if(gamer < 0 || gamer > 4)
                {
                    puts("Enter a number in the range of 1 to 4.");
                    continue;
                }

                COM_gawi_bawi_bo[computer-1]++;
                SRM_gawi_bawi_bo[gamer-1]++;

                check_game(gamer, computer);
    }
}

void check_game(int gamer, int computer)
{
    int flag;
    static int count_win=0, count_lose=0;

    switch(gamer)
    {
        case GAWI:
        flag = computer == BO? WIN : computer == BAWI?LOSE : TIE;
        break;
        case BAWI:
        flag = computer == GAWI? WIN : computer == BO?LOSE : TIE;
        break;
        case BO:
        flag = computer == BAWI? WIN : computer == GAWI?LOSE : TIE;
        break;
    }

    if(flag == WIN)
    {
        puts("\n^..^ I won. Earn 5,000 won ^.^\n");
        point += 5000;
        if(++count_win == 3)
        {
            puts("Was more than three times consecutive wins. Bonus paid 10,000 won\n");
            point += 10000;
        }
        else if(count_win >= 5)
        {
            puts("Was more than five times consecutive wins. Bonus paid 30,000 won\n");
            point += 30000;
        }
        count_lose = 0;
    }
    else if(flag == LOSE)
    {
        puts("\nㅠ.ㅠ Lost 10000 won ... Depressed mode ...\n");
        point -= 5000;

        if(--count_lose == -3)
        {
            puts("Was more than three times consecutive loses. Lost 10,000 won\n");
            point -= 10000;
        }
        else if(count_lose <= -5)
        {
            puts("Was more than five times consecutive loses. Lost 30,000 won\n");
            point -= 30000;
        }
        count_win = 0;
    }
    else
    {
        puts("\n-,.- It was drawn. Let's do it again ... ^&^\n");
    }
}
