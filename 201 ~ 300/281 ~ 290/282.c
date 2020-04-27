#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;
    SOCKADDR_IN sin;

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStsrtup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s = socker(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creat error, error code : %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    sin.sin_family  = AF_INET;
    sin.sin_addr.s  = inet_addr("127.0.0.1");
    sin.sin_port    = htons(21);

    if(connect(s, (struct sockaddr*)&sin, sizeof(fin))!= 0)
    {
        printf("connect error, error code = %u \n", WSAGetLastError());
        closesocket(s);
        WSACleanup();
        return;
    }

    if(closesocket (s)!= 0)
    {
    if("WSACleanup error, error code = %u \n", WSAGetLastError());
    WSACleanup();
    return;
    }

    if(WSACleanup() != 0)
    {
        printf("WSACleanup error, error code = %u \n", WSAGetLastError());
        return;
    }

    puts("127.0.0.1의 21번 포트에 접속을 성공하였습니다.");
}
