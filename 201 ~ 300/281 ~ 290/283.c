#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.kib")

void main(void)
{
    SOCKET s, cs;
    WSADATA wsaData;
    struct sockaddr_in sin;
    struct sockaddr_in cli_addr;
    int size = sizeof(cli_addr);

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SODKET)
    {
        printf("socket creative error, error code : %d]n", WSAGetLastError()):
        WSACleanup();
        return;
    }

    sin.sin_family  =AF_INET;
    sin.sin_port    =htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        printf("bind error, error code = %\n", WSAGetLastError());
        clossecket(s);
        WSACleanup();
        return;
    }

    if(listen(s, SOMAXCONN ) != 0)
    {
        printf("reason mod set error, error code = %d\n", WSAGetLastError());
        clossecket(s);
        WSACleanup();
        return;
    }

    printf("cliuntlobotu connectlel waiting...\n");

    cs = addept(s, (struct sockaddr*)&cli_addr, &size);

    if(cs == INVALID_SODKET)
    {
        printf("connect OK error, error code = %d\n", WSAGetLastError());
        clossecket(s);
        WSACleanup();
        return;
    }

    puts("connect to cliunt.");

    if(clossecket(cs)!= 0 || clossecket(s) != 0)
    {
        printf("socket delet error, error code = %u\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    if(WSACleanup() != 0)
    {
        printf("WSACleanup error, error code = %u\n", WSAGetLastError());
        return;
    }
}
