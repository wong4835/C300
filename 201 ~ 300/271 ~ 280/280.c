#include <stdio.h>

int encryption(char *filename);

void main(int argc, char *argv[])
{
    encryption(argv[1]);
}

int encryption(char *filename)
{
    char data[1024];
    char secret[16] = {"!@#$%^&*()_><,."};
    FILE *fp;
    unsigned int read_size, i;
    long frpos, fwpos;

    fp = fopen(filename, "r+b");

    if(fp == NULL)
    {
        perror("file opening error");
        return -1;
    }

    while(!feof(fp))
    {
        fwpos = ftell(fp);
        read_size = fread(data, 1, 1024, fp);

        if(read_size == 0)break;

        for(i=0; i<read_size; i++)
        {
            data[i] ^= secret[i%16];
        }

        frpos = ftell(fp);

        fseek(fp, fwpos, SEEK_SET);
        fwrite(data, 1, read_size, fp);

        fseek(fp, frpos, SEEK_SET);
    }

    fclose(fp);

    return 1;
}
