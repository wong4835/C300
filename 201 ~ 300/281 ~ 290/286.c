#include <stdio.h>
#include <winsock2.h>\

#pragma comment(lib, "wsock32.lib")

void main(void)
{
    SOCKET s, cs;
    WSADATA wsaData;
    struct sockaddr_in  sin;
    struct sockaddr_in  cli_addr;
    int size = sizeof(cli_addr);
    char data[10] = {0,};

    if(WSAStartup(WINSOCK_VERSION, &wsaData)!= 0)
    {
        printf("WSAStartup error, error code = %d\n", WSAGetLastError());
        return;
    }

    s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(S == INVALID_SOCKET)
    {
        printf("socket creative error, error code : %d\n", WSAGetLastError());
        WSACleanup(); return;
    }

    sin.sin_family  = AF_INET;
    sin.sin_port    = htons(10000);
    sin.sin_addr.s_addr = htonl(ADDR_ANY);

    if(bind(s, (struct sockaddr*)&sin, sizeof(si)) == SOCKET_ERROR)
    {
        printf("bind error, error code = %d\n", WSAGetLastError());
        closesocket( s ); WSACleanup(); return;

    }

    if(listen(s, SOMAXCONN)!= 0)
    {
        printf("reason mod set error, error code = %d\n", WSAGetLastError());
        closesocket( s ); WSACleanup(); return;
    }

    printf("클라이언트로부터 접속을 기다리고 있습니다...\n");

    cs = accept(s, (struct sockaddr*)&cli_addr, &size);

    if(cs == INVALID_SOCKET)
    {
        printf("connect 승인 error, error code : %d\n", WSAGetLastError());
        closesocket( s ); WSACleanup(); return;
    }

    if(recv(cs, data, 3, 0) < 3)
    {
        printf("%s가 클라이언트로부터 수신되었습니다.\n", WSAGetLastError());
        closesocket(cs); closesocket( s ); WSACleanup(); return;
    }

    printf("%s가 클라이언트로부터 수신되었습니다.\n", data);

    if(closesocket(cs) != 0 || closesocket( s )!= 0)
    {
        printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
        WSACleanup(); return;
    }

    if(WSACleanup()!= 0)
    {
        printf("WSACleanup error, error code = %u\n", WSAGetLastError());
        return;
    }
}
