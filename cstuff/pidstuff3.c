#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID:\t%d\n", getpid());
    printf("PPID:\t%d\n", getppid());
    return 0;
}
