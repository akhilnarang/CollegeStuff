#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 1024

int main() {
    int sockfd, accept_socket, length;
    struct sockaddr_in server;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Socket creation failed!\n");
        exit(1);
    }
    printf("Socket successfully created!\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8000);

    if ((bind(sockfd, (struct sockaddr*)&server, sizeof(server))) < 0) {
        printf("Socket bind failed!\n");
        exit(1);
    }
    printf("Socket successfully bound!\n");

    if (listen(sockfd, 1) != 0) {
        printf("Listen failed!\n");
        exit(1);
    }
    length = sizeof(server);
    if ((accept_socket = accept(sockfd, (struct sockaddr*)&server,
                                (socklen_t*)&length)) < 0) {
        printf("Connection not accepted!\n");
        exit(1);
    }

    char* message;
    char buffer[MAX] = {0};
    int value = read(accept_socket, buffer, MAX);
    printf("Received: %s\n", buffer);
    printf("Enter a message!\n");
    printf("message: ");
    fgets(message, MAX, stdin);
    send(accept_socket, message, strlen(message), 0);
    close(sockfd);
}