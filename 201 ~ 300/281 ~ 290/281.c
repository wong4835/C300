#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStsrtup error, error code = %d\n", WSAGetLastError());
        return;
    }

    puts(wsaData.szDescription);
    puts(wsaData.szSystemStatus);

    s=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creat error, error code :  %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    if(closesocket(s) != 0)
    {
        printf("socket delet error, error code = %u \n", WSAGetLastError());
        WSACleanup();
        return;
    }

    if(WSACleanup() != 0)
    {
        printf("WSACleanup error, error code = %u \n", WSAGetLastError());
        return;
    }

    puts("We can use winsock.");
}
