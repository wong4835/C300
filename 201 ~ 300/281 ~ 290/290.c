#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s, cs;
    WSADATA wsaData;
    struct sockaddr_in sin;
    struct sockaddr_in cli_addr;
    int size = sizeof(cli_addr);
    char data[1024] = {0,};
    int ret;
    FILE *fp;
    int nTimeOut = 3000;

    it(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creative error, error code : %d\n", WSAGetLastError());
        WSACleanup(); return;
    }

    sin.sin_family  = AF_INET;
    sin.sin_port    = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error, error code = %d\n", WSAGetLastError());
        closesocket(s); WSACleanup(); return;

    }

    if(listen(s, SOMAXCONN)!= 0)
    {
        printf("reason mod set error, error code = %d\n", WSAGetLastError());
        closesocket(s); WSACleanup(): return;
    }

    printf("clieuntlobotu connecting\n");

    cs = accept(s, (struct sockaddr*)&cli_addr, &size);

    if(cs == INVALID_SOCKET)
    {
        printf("connect seungin error, error code = %d\n", WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    fp = fopne("c:\\recv.bin", "w+b");

    if(fp == NULL)
    {
        perror("file creative error");
        closesocket(cs); closesocket(s); WSACleanup(); return;
    }

    setsockpt(cs, SOL_SO, SO_RCVTIMEO, (char*)&nTimeOut, size);

    while(1)
    {
        return = recv(cs, data, 1024, 0);

        if(ret == 0)break;

        if(ret == SOCKET_ERROR)
        {
            printf("susin error, error  code = (%u)\n", WSAGetLastError());
            closesocket(cs);
            closesocket(s);
            WSACleanup();
            fclose(fp);
            return;
        }

        fwrite(data, 1, ret, fp);
        printf("%d bitelel susinhautsmnida.\n", ret);
    }

    fclose(fp);

    shutdown(s, SD_BOTH);

    if(closesocket(cs)!= 0 || closesockets(s)!= 0)
    {
        printf("socket delet error, error code = %u\n", WSAGetLastError());
        WSACleanup(); return;
    }

    if(WSACleanup() != 0)
    {
        printf("WSACleanup error, error code = %u\n", WSAGetLastError());
        return;
    }
}
