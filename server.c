#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<limits.h>
#include<arpa/inet.h>

#define PORT 8080
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

    // Get Message
    printf("Please enter a message \n");
    fgets(hello, MAXLINE, stdin);
    int length_buf = strlen(hello);

    if(bind(sock, (struct sockaddr *) &serverAddr, addlen) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    if(sendto(sock, (const char *)hello, length_buf, MSG_CONFIRM, (struct sockaddr *)&serverAddr, addlen) < 0) {
        perror("Send to Failed");
        exit(EXIT_FAILURE);
    }

    length_get = recvfrom(sock, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&serverAddr, &len);
    buffer[length_get] = '\0';
    printf("Server : %s\n", buffer);

    close(sock);

    return 0;
}
