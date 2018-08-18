#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<time.h>

#define PORT 8090

char * getCurrentTime() {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char * presentTime;
    presentTime = (char *) calloc(sizeof(char), 100);
    sprintf(presentTime, "Date is %d %d %d and Time %d:%d", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min);

    return presentTime;
}

int main(int c, char ** args) {
    getCurrentTime();
    struct sockaddr_in serverAddr;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4500);
    
    char buffer[1024];
    char hello[1024];

    int sock, sendto_r, recievefrom_s, length_get, len;
    int opt = 1;

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

    if(bind(sock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        int t;
        // Get Message
        char * timenow;
        timenow = (char *) calloc(sizeof(char), 100);
        timenow = getCurrentTime();

        if(sendto(sock, (const char *)timenow, strlen(timenow), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Send to Failed");
            exit(EXIT_FAILURE);
        }

        sleep(5);
    }

    close(sock);

    return 0;
}