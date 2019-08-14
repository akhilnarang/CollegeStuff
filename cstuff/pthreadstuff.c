#include <pthread.h>
#include <stdio.h>

// Function to add 2 numbers in array and store result
void add(int n[3]) {
    n[0] = n[1] + n[2];
    printf("Sum of %d and %d is %d!\n", n[1], n[2], n[0]);
}

int main() {
    int m[3], n[3], result;
    // Declaring our pthreads
    pthread_t t1, t2;
    // Prompting the user
    printf("Enter 4 numbers\n");
    // Accepting 4 numbers from the user
    scanf("%d%d%d%d", &m[1], &m[2], &n[1], &n[2]);
    // Creating the pthreads
    pthread_create(&t1, NULL, (void*)add, m);
    pthread_create(&t2, NULL, (void*)add, n);
    // Joining the pthreads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // Adding the 2 sums
    result = m[0] + n[0];
    // Displaying the final result
    printf("Final answer is %d!\n", result);
    return 0;
}
