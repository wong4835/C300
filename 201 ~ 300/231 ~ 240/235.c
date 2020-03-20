#include <stdio.h>

void main(void)
{
    FILE *fp;
    char *string = "Woori Gangsan, m\n";

    fp = fopen("c:\\file.txt", "w+");

    if(fp != NULL)
    {
        fwrite(string, 1, strlen(string), fp);
        fwrite(string, 1, strlen(string), fp);
        fwrite(string, 1, strlen(string), fp);
        fclose(fp);
    }
}
