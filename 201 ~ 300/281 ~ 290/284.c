#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s, cs;
    WSADATA wsaData;
    struct sockaddr_in  sin;
    struct sockaddr_in  cli_addr;
    int size = sizeof(cli_addr);

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s= socket(AF_INER, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creat error, error code = %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    sin.sin_family  = AF_INET;
    sin.sin_port    = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("find error, error code = %d\n", WSAGetLastError());
        closesocket(S);
        WSACleanup();
        return;
    }

    if(listen(s, SOMAXCONN)!= 0)
    {
        printf("reson mod set error, error code = %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return;
    }

    printf("클라이언트로부터 접속을 기다리고 있습니다... \n");

    cs = accept(s, (struct sockaddr*)&cli_addr, &size);

    if(cs == INVALID_SOCKET)
    {
        printf("접속 승인 실패, error code = %d\n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return;
    }

    puts("connect to 클라이언트");

    if(closesocket(cs)!= 0 || closesocket(s)!= 0)
    {
        printf("socket delet error, error code = %u\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    if(WSACleanup()!= 0
    {
        printf("WSACleanup error, error code = %u\n", WSAGetLastError());
        return;
    }
}
