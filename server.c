#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<limits.h>
#include<arpa/inet.h>

#define PORT 5000
#define MAXLINE 1024

int main(int c, char ** args) {

    struct sockaddr_in serverAddr;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    
    int addlen = sizeof(serverAddr);
    char buffer[MAXLINE];
    char hello[MAXLINE];

    int sock, sendto_r, recievefrom_s, length_get, len;

    if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("Failed");
        exit(EXIT_FAILURE);
    }else {
        printf("Socket ID: %d\n", sock);
    }

    if(bind(sock, (struct sockaddr *) &serverAddr, addlen) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }else {
        printf("as");
    }

    while(1) {
        // Recieve From
        length_get = recvfrom(sock, (char *)buffer, MAXLINE, 0, (struct sockaddr *)&serverAddr, &len);
        buffer[length_get] = '\0';
        printf("Server : %s\n", buffer);
    }

    

    return 0;
}
