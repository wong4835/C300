#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;
    struct sockaddr_in  sin;
    char data[10] = "abc";

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStartup error, error code = &d \n", WSAGetLastError());
        return;
    }

    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creat error, error code : %d\n", WSAGetLastError());
        WSACleanup(); return;
    }

    sin.sin_family  = AF_INET;
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_port    = htons(10000);

    if(connect(s, (struct sockaddr*)&sin, sizeof(sin))!= 0)
    {
        printf("connect error, error code = %u\n", WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    if(send(s, data, 3, 0)< 3)
    {
        printf("data send error, error code = %u\n", WSAGetLastError());
        closesocket(s); WSACleanup(); return;
    }

    puts("We send abc to server program")

    if(closesocket(s)!= 0)
    {
        printf("socker delet error, error code = %u\n", WSAGetLastError());
        WSACleanup(); return;
    }

    if(WSACleanup()!= 0)
    {
        printf("WSACleanup error, error code = %u\n", WSAGetLastError());
        return;
    }
}
