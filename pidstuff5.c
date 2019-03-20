#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    int status;
    if (pid == 0) {
        printf("In pidstuff5 child, before execlp()\n");
        execlp("./pidstuff6", "", NULL);
        exit(100);
    } else if (pid > 0) {
        printf("In pidstuff5 parent, before wait()\n");
        wait(&status);
        printf("In pidstuff5 parent, waited for child to execute!\n");
        printf("Child status: %d\n", WEXITSTATUS(status));
    } else {
        perror("Error forking!\n");
        _exit(1);
    }
    printf("In pidstuff5, before returning\n");
    return 0;
}
