#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>


int main(int argc, char const *argv[])
{
    int sock, newsock, opt=1, sizeAddr, readFlag;
    struct sockaddr_in serverAddr;
    char buffer[1024] = {0};
    char sendBuffer[1024] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0 ) {
        perror("Socket Creation");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("SetSockOpt Error");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(5600);
    serverAddr.sin_family = AF_INET;
    sizeAddr = sizeof(serverAddr);

    if(bind(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind Error");
        exit(EXIT_FAILURE);
    }

    if(listen(sock, 5) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    if(newsock = accept(sock, (struct sockaddr *)&serverAddr, (socklen_t *)&sizeAddr) < 0) {
        perror("Accept");
        exit(EXIT_FAILURE);
    }

    readFlag = read(newsock, buffer, 1024);
    printf("%s\n", buffer);
    
    send(newsock , sendBuffer , strlen(sendBuffer) , 0 );
    printf("Message sent\n");

    return 0;
}
