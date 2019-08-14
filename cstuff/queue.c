/*
 * queue.c
 *
 *      Author: Akhil Narang
 * Roll Number: 203132
 */

#include <stdio.h>

int front = 0, rear = 0, size;

int insert(int ch, int q[]) {
    if ((rear + 1) % size == front) {
        return 1;
    }

    rear = (rear + 1) % size;
    q[rear] = ch;

    return 0;
}

int delete (int q[]) {
    if (front == rear) {
        return -1;
    }

    front = (front + 1) % size;
    return q[front];
}

void display(int q[]) {
    printf("\n{ ");

    if (front == rear) {
        printf("}\n");
        return;
    }
    for (int i = (front + 1) % size; (i + 1) % size == rear;
         i = (i + 1) % size) {
        printf("%d, ", q[i]);
    }

    printf("%d }\n", q[rear]);
}

int main() {
    printf("Enter size of queue!\n");
    printf("size: ");
    scanf("%d", &size);
    int q[size];
    int choice;

    do {
        printf(
            "1. Insert an order\n2. Deliver an order\n3. Display all orders\n");
        printf("choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter order id to insert!\n");
                printf("id: ");
                scanf("%d", &choice);
                if (insert(choice, q)) {
                    printf("Can't take any more orders!\n");
                } else {
                    printf("Order %d inserted!\n", choice);
                }
                break;

            case 2:
                choice = delete (q);
                if (choice == -1) {
                    printf("No orders to deliver!\n");
                } else {
                    printf("Delivered order %d!\n", choice);
                }
                break;

            case 3:
                display(q);
                break;

            default:
                printf("Invalid input!\n");
                break;
        }

        printf("Do you want to continue? 0 to exit!\n");
        printf("choice: ");
        scanf("%d", &choice);
    } while (choice);
}
