#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        if (!fork()) {
            printf("Child: %d, Parent: %d\n", getpid(), getppid());
            exit(0);
        }
    }
    for (i = 0; i < 5; i++) {
        wait(NULL);
    }
}
