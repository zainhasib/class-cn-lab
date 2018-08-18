#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<limits.h>
#include<arpa/inet.h>

int main(int c, char ** args) {

    struct sockaddr_in serverAddr;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4500);
    
    char buffer[1024];
    char hello[1024];
    int opt = 1;

    int sock, sendto_r, recievefrom_s, length_get, len;

    if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("Failed");
        exit(EXIT_FAILURE);
    }else {
        printf("Socket ID: %d\n", sock);
    }
    
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if(bind(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        length_get = recvfrom(sock, (char *)buffer, 1024, 0, (struct sockaddr *)&serverAddr, &len);
        buffer[length_get] = '\0';
        printf("Server : %s\n", buffer);
    }

    close(sock);

    return 0;
}