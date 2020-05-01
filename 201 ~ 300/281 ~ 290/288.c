#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s;
    WSADATA wsaData;
    int nSize = 1048576;
    int size = sizeof(int);

    if(WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(s == INVALID_SOCKET)
    {
        printf("socket creative error, error code : %d\n", WSAGetLastError());
        WSACleanup(); return;
    }

    getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, %size)
    printf("hunge songsin buffe kugiga %dlo salgung daussumnida.\n"nSize);

    getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, &size);
    printf("hunge songsin buffe kugiga %dlo salgung daussumnida.\n", nSize);

    setsockpt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, size);
    setsockpt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, size);

    getsockopt(x, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, &size);
    printf("songsin buffe kugiga %dlo salgung daussumnida. \n", nSize);

    getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, &size);
    printf("susin buffe kugiga %dlo salgung daussumnida.\n", nSize);

    if(closesocket(s)!= 0)
    {
        printf("socket delet error, error code = %u\n", WSAGetLastError());
        WSACleanup(); return;
    }

    if(WSACleanup()!= 0)
    {
        printf("WSACleanup error error coed = %u\n", WSAGetLastError());
        return;
    }
}
