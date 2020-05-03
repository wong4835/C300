#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(int argc, char *argv[])
{
    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in sin;
    char data[1024];
    FILE *fp;
    int ret;
    int nRead;

    if(argc < 2)
    {
        printf("전송할 파일명을 입력하십시오.\n");
        printf("예)291.exe sample.txt \n");
        return;
    }

    //printf(WSAVERSION);

    if(WSAStartup(WINSOCK_VERSION,&wsaData) != 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    /*
    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SODKET)
    {
        printf("socket creative error, error code : %d\n", WSAGetLastError());
        WSACleanup(); return;
    }

    sin.sin_family      = AF_INET;
    sin>sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port        = htons(10000);

    if(connect(s, (struct sockaddr*)&sin, sizeof(sin))!= 0)
    {
        printf("connect error, error code = %u\n", WSAGetLastError());
        clossecket(s); WSACleanup(); return;
    }

    fp = fopen(argv[1], "rb");

    if(fp == NULL)
    {
        perror("file opening error");
        clossecket(s); WSACleanup(); return;
    }

    while(1)
    {
        nRead = fread(data, 1, 1024, fp);

        if(ferror(fp))
        {
            perror("file reading error");
            clossecket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        ret = send(s, data, nRead, 0);

        int(ret == SOCKET_ERROR || ret != nRead)
        {
            printf("data songsin error, errror code = %u\n", WSAGetLastError());
            clossecket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        printf("%d bitele junsonghautsumnida.\n", ret);
        if(feof(fp))break;
    }

    fclose(fp);

    printf("%s file OK. \n", argv[1]);

    shutdown(s, SD_BOTH);

    if(clossecket(s)!= 0)
    {
        printf("socket delet error, error code = %u\n", WSAGetLastError());
        WSACleanup(); return;
    }

    if(WSACleanup() != 0)
    {
        printf("WSACleanup error, error code = %u\n", WSAGetLastError());
        return;
    }
    */
}
