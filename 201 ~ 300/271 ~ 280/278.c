#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE    "C:\\C_it\\data\\abc0108.txt"
#define ANSWERFILE  "C:\\C_it\\data\\Ans4.txt"

typedef struct tagData
{
    char no[7];
    char code;
    int hobong;
    char mail[5];
    char bonbong;
    int sangyuilkum;
    int kongjeak;
    int mechulak;
    int mechulpoint;
    char insakokwa;
    char kunmujigubum;
    int hap;
}data;

data D[1000], S[100], T;
int nStartLine, nEndLine;
FILE *fp;
char buff[200];
int i=0, j, k, hap;

void main(int argc, char *argv[])
{
    if(argc < 3)
    {
        puts("인수를 입력하십시오");
        return;
    }

    nStartLine = atoi(argv[1]);
    nEndLine   = atoi(argv[2]);

    fp = fopen(DATAFILE, "r");

    if(!fp)
    {
        perror("파일 개방 에러");
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

        D[i].kunmujigubum   = buff[29];
        D[i].insakokwa      = buff[28];            buff[28] = 0;
        D[i].mechulpoint    = atoi(&buff[25]);     buff[25] = 0;
        D[i].mechulak       = atoi(&buff[22]);     buff[22] = 0;
        D[i].kongjeak       = atoi(&buff[19]);     buff[19] = 0;
        D[i].sangyuilkum    = atoi(&buff[16]);     buff[16] = 0;
        D[i].bonbong        = atoi(&buff[13]);     buff[13] = 0;
        strncpy(D[i].mail, &buff[9], 4);
        D[i].hobong         = atoi(&buff[7]);
        D[i].code           =buff[6];
        strncpy(D[i].no, &buff[0], 6);

        if(D[i].kunmujigubum == 'A')    D[i].hap = D[i].mechulpoint + 10;
        if(D[i].kunmujigubum == 'B')    D[i].hap = D[i].mechulpoint + 20;
        if(D[i].kunmujigubum == 'C')    D[i].hap = D[i].mechulpoint + 30;

        i++;
    }

    fclose(fp);

    j = 0;

    for(i=nStartLine-1; i<nEndLine; i++)
    {
        if(D[i].code == 'C')
        {
            hap += D[i].hap;
        }
    }

    fp = fopen(ANSWERFILE, "w+");
    fprintf(fp, "%d %d %d", nStartLine, nEndLine, hap);
    fclose(fp);
}
