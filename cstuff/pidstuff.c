#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t pid;

int main() {
    pid = fork();
    if (pid == 0) {
        printf("Child: %d\n", pid);
    } else if (pid > 0) {
        printf("Parent: %d\n", pid);
    } else {
        perror("Fork failed\n");
        _exit(2);
    }
}
