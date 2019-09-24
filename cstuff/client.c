#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 1024

int main() {
    int sockfd;
    struct sockaddr_in server;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Socket could not be created!\n");
        exit(1);
    }

    printf("Socket created!\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8000);

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) != 0) {
        printf("Connection with the server failed!\n");
        exit(1);
    }
    printf("Connected to the server!\n");

    char* message;

    printf("Enter a message!\n");
    char buffer[MAX] = {0};
    printf("message: ");
    fgets(message, MAX, stdin);
    send(sockfd, message, strlen(message), 0);
    int value = read(sockfd, buffer, 1024);
    printf("Received: %s\n", buffer);
    close(sockfd);
}