/*
 * linkedlist.c
 *
 *  Created on: 21-Jan-2019
 *      Author: Akhil Narang
 * Roll Number: 203132
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node *next;
} node;


void create(node *head) {
	node *temp = head;
	int ch;
	do {
		node *current = malloc(sizeof(node));
		current->next = NULL;
		printf("Enter integer!\n");
		printf("n: ");
		int n;
		scanf("%d", &n);
		current->data = n;
		temp->next = current;
		temp = current;
		printf("Enter 0 to stop, any other integer to continue!\n");
		printf("ch: ");
		scanf("%d", &ch);
	} while (ch != 0);
}

void display(node *head) {
	if (head->next == NULL) {
		printf("Empty list!\n");
		return;
	}
	printf("Current Address\tCurrent Data\tNext Address\n");
	do {
		head=head->next;
		printf("%d\t%d\t\t%d\n", head, head->data, head->next);
	} while (head->next != NULL);
}
int main() {
	node *head = malloc(sizeof(node));
	head->next = NULL;
	create(head);
	display(head);
}



