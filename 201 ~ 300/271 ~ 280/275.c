#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE    "C:\\C_it\\data\\abc0108.txt"
#define ANSWERFILE    "C:\\C_it\\data\\Ans1.txt"

typedef struct tagData
{
    char no[7];
    char code;
    int hobong;
    char mail[5];
    int bonbong;
    int sangyuilkum;
    int kongjeak;
    int mechulak;
    int mechulpoint;
    char insakokwa;
    char kunmujigubum;
    int hap;
}data;

data D[1000], S[1000], T;
int nStartLine, nEndLine;
FILE *fp;
char buff[200];
int i=0, j, k;

void main(int argc, char *argv[])
{
    if(argc < 3)
    {
        puts("인수를 입력하세오.");
        return;
    }

    nStartLine = atoi(argv[1]);
    nEndLine   = atoi(argv[2]);

    fp = fopen(DATAFILE, "r");

    if(!fp)
    {
        perror("file opening error");
        return;
    }

    while(!feof(fp))
    {
        fgets(buff, 200, fp);

        if(ferror(fp))
        {
            perror("file reading error");
            fclose(fp);
            return;
        }

        if(feof(fp))break;

        D[i].kunmujigubum   =buff[29];
        D[i].insakokwa      =buff[28];
        D[i].mechulpoint    =atoi(&buff[25]);   buff[25] = 0;
        D[i].mechulak       =atoi(&buff[22]);   buff[22] = 0;
        D[i].kongjeak       =atoi(&buff[19]);   buff[19] = 0;
        D[i].sangyuilkum    =atoi(&buff[16]);   buff[16] = 0;
        D[i].bonbong        =atoi(&buff[13]);   buff[13] = 0;
        strncpy(D[i].mail, &buff[9], 4);        buff[9] = 0;
        D[i].hobong          =atoi(&buff[7]);
        D[i].code            =buff[6];
        strncpy(D[i].no, &buff[0], 6);
        D[i].hap = D[i].bonbong + D[i].sangyuilkum;

        i++;
    }

    fclose(fp);

    j = 0;

    for(i=nStartLine-1; i<nEndLine; i++)
    {
        if(D[i].mechulpoint > 20)
        {
            S[j++] = D[i];
        }
    }

    for(i=0; i<j-1; i++)
    {
        for(k=i+1; k<j; k++)
        {
            if(S[i].hap > S[k].hap)
            {
                T = S[i];
                S[i] = S[k];
                S[k] = T;
            }
            else if(S[i].hap == S[k].hap)
            {
                if(strcmp(S[i].no, S[k].no) > 0)
                {
                    T = S[i];
                    S[i] = S[k];
                    S[k] = T;
                }
            }
        }
    }

    fp = fopen(ANSWERFILE, "w+");
    fprintf(fp, "%d %d %d", nStartLine, nEndLine, S[4].hap);
    fclose(fp);
}
