#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(int aggc, char *argv[])
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
        printf("junsonghal filename enter. \n");
        printf("ex)291.exe sample.txt\n");
        return;
    }

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creative error errror code : %d\n", WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    sin.sin_family      = AF_INET;
    sin.sin_addr.s_addr = inet_addr("127.0.0.");
    sin.sin_port        = htons(10000);

    if(connect(s, (struct sockaddr*)&sin, sizeof(cin)) != 0)
    {
        printf("connect error, error code = %u\n", WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    fp = fopen(argv[1], "rb");

    if(fp == NULL)
    {
        perror("file opening error");
        closesocket(s); WSACleanup(); return;
    }

    while(1)
    {
        nRead = fread(data, 1, 1024, fp);

        if(ferror(fp))
        {
            perror("file reading error");
            closesocket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        ret = send(s, data, nRead, 0);

        if(ret == SOCKET_ERROR || ret != nRead)
        {
            printf("data songsin error, error code = %u\n", WSAGetLastError());
            closesocket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        printf("%d batelel songsin halutsumnida. \n", ret);
        if(feof(fp))break;
    }

    fclose(fp);

    printf("%s fileul junsonghalultsumnida.\n", argv[1]);

    shutdown(s, SD_BOTH);

    if(closesocket(s)!= 0)
    {
        printf("socket delt")
    }
}
