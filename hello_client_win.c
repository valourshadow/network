#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void ErrorHandling(char* message);

int main(int argc, char* argv[])
{
    WSADATA wsaData;
    SOCKET  hSocket;
    SOCKADDR_IN servAddr;

    char message[30];
    int strlen;
    if(argc!=3)
    {
        printf("Usage : %s <IP>  <port>\n", argv[0]);
        exit(1);
    }

    if(WSAStartup(MAKEWORD(2 ,2),&wsaData)!=0)
    {
        ErrorHandling((char*)"WSAStartup() error");
    }

    hSocket=socket(PF_INET, SOCK_STREAM, 0);
    if (hSocket==INVALID_SOCKET)
    {
        ErrorHandling((char*)"socket() error");
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family=AF_INET;
    servAddr.sin_addr.S_un.S_addr=inet_addr(argv[1]);
    servAddr.sin_port=htons(atoi(argv[2]));

    if(connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr))==SOCKET_ERROR)
    {
        ErrorHandling((char*)"connect() error!");
    }

    strlen=recv(hSocket, message, sizeof(message)-1, 0);
    if (strlen==-1)
    {
        ErrorHandling((char*)"read() error!");
    }
    printf("Message from server : %s\n", message);

    closesocket(hSocket);
    WSACleanup();
    return 0;
}


void ErrorHandling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}