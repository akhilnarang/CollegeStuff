#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080

// Function designed for chat between client and server.
void func(int sockfd) {
    char buff[MAX];
    int n;
    // Infinite loop for chat
    for (;;) {
        bzero(buff, MAX);

        // Read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff));
        // Print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // Copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;

        // And send that buffer to client
        write(sockfd, buff, sizeof(buff));

        // If msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

// Driver function
int main() {
    int sockfd, connfd, len;
    struct sockaddr_in server, cli;

    // Socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    } else
        printf("Socket successfully created..\n");
    bzero(&server, sizeof(server));

    // Assign IP ands port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (struct sockaddr*)&server, sizeof(server))) != 0) {
        printf("Socket bind failed!\n");
        exit(0);
    } else
        printf("Socket successfully bound!\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    } else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
        printf("Server did not acccept, or it failed!\n");
        exit(0);
    } else
        printf("Server has acccepted the client!\n");

    // Function for chatting between client and server
    func(connfd);

    // After chatting close the socket
    close(sockfd);
}