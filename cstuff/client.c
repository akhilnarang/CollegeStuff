#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080

void func(int sockfd) {
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the string: ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From server: %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client exit...\n");
            break;
        }
    }
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in server, cli;

    // Socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed!\n");
        exit(0);
    } else
        printf("Socket successfully created!\n");
    bzero(&server, sizeof(server));

    // Assign IP and port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(PORT);

    // Connect the client socket to server socket
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) != 0) {
        printf("Connection with the server failed!\n");
        exit(0);
    } else
        printf("Connected to the server!\n");

    // Function for chat
    func(sockfd);

    // Close the socket
    close(sockfd);
}