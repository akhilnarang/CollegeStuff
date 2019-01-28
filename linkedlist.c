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


void create(node *head)
{
    printf("Creating list!\n");
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

void display(node *head)
{
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

int length(node *head) {
    int c = 0;
    while (head->next != NULL) {
        c++;
        head = head->next;
    }
    return c;
}


void insert(node *head)
{
    int key, n;
    printf("Enter location of data!\n");
    printf("key: ");
    scanf("%d", &key);
    if (key >= length(head)) {
        printf("Key does not exist!\n");
        return;
    }
    printf("Enter data to be inserted!\n");
    printf("n: ");
    scanf("%d", &n);
    for(int i=1; i<key; i++) {
        head = head->next;
    }
    node *new = malloc(sizeof(node));
    new->next = head->next;
    head->next = new;
    new->data = n;
}

node* delete(node* head)
{
	node *p, *c, *t;
	int i = 0, key;
	printf("Enter key to be deleted!\n");
	printf("key: ");
	scanf("%d", &key);
	c = head;
	p = head;

	while(c != NULL) {
		i++;
		if((c->data == key) && (i==1)) {
			t = head;
			head = head->next;
			free(t);
			break;
		} else if(c->data == key) {
			t = p->next;
			p->next = c->next;
			free(t);
			break;
		} else {
			p = c;
			c = c->next;
		}
	}
	return head;
}

void reverse(node *head)
{
    node *curr = malloc(sizeof(node));
    node *prev = malloc(sizeof(node));
    node *future = malloc(sizeof(node));            
	curr = head->next;
	prev = NULL;
	while(curr!=NULL) {
		future = curr->next;
		curr->next = prev;
		prev = curr;
		curr = future;
	}

	head->next = prev;
}

void sort(node *head)
{
    node *curr = malloc(sizeof(node));
    node *prev = malloc(sizeof(node));
    node *temp = malloc(sizeof(node));    
	int len, i, j;
	len = length(head);
	for(i = 1; i<=len ;i++) {
		prev = head;
		curr = head->next;
		for(j = 1; j<=len-i ;j++) {
			temp = curr->next;
			if(curr->data > temp->data) {
				prev->next = temp;
				curr->next = temp->next;
				temp->next = curr;
				prev = temp;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

void merge(node *head1, node *head2) {
	int flag;
    node *curr1 = malloc(sizeof(node));
    node *curr2 = malloc(sizeof(node));
    node *temp = malloc(sizeof(node));    
	curr1 = head1->next;
	curr2 = head2->next;
	if(curr1->data < curr2->data) {
		temp = head1;
		flag = 1;
	} else {
		temp = head2;
		flag = 0;
	}

	while(curr1 != NULL && curr2 != NULL) {
		if(curr1->data < curr2->data) {
			temp->next = curr1;
			temp = curr1;
			curr1 = curr1->next;
		} else {
			temp->next = curr2;
			temp = curr2;
			curr2 = curr2->next;
		}
	}

		if(curr1==NULL) {
			temp->next = curr2;
		}
		if(curr2==NULL) {
			temp->next = curr1;
		}
		if(flag==1) {
			display(head1);
		} else {
			display(head2);
		}
}

void erase(node *head)
{
    if (head->next == NULL) return;
    node *temp = malloc(sizeof(node));
    node *future = malloc(sizeof(node));
    temp = head;
	do {
		future = temp->next;
		free(temp);
		temp = future;
	} while (temp != NULL);
    head->next = NULL;
}

int main()
{
    int ch;
	node *head = malloc(sizeof(node));
    node *list1 = malloc(sizeof(node));
    node *list2 = malloc(sizeof(node));	
	head->next = NULL;
        create(head);
        do {
            printf("Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!\n");
            printf("ch: ");
            scanf("%d", &ch);  
            switch(ch) {
                case 1:
                    display(head);
                    break;
                case 2:
                    insert(head);
                    break;
                case 3:
                    head = delete(head);
                    break;
                case 4:
                    printf("Length of list is %d!\n", length(head));
                    break;
                case 5:
                    reverse(head);
                    break;
                case 6:
                    sort(head);
                    break;
                case 7:
                    create(list1);
                    create(list2);                 
                    merge(list1, list2);
                    break;
                case 8:
                    erase(head);
                    break;
                case 0: break;
                default: printf("Wrong choice!\n");
            }
        } while (ch!=0);
}

/*OUTPUT
Creating list!
Enter integer!
n: 1
Enter 0 to stop, any other integer to continue!
ch: 1
Enter integer!
n: 2
Enter 0 to stop, any other integer to continue!
ch: 0
Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!
ch: 1
Current Address	Current Data	Next Address
36312192	1		36313264
36313264	2		0
Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!
ch: 8
Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!
ch: 1
Empty list!
Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!
ch: 0
mitwpu@C04L0929A:~$ ./a.out 
Creating list!
Enter integer!
n: 1
Enter 0 to stop, any other integer to continue!
ch: 0
Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!
ch: 7
Creating list!
Enter integer!
n: 1
Enter 0 to stop, any other integer to continue!
ch: 1
Enter integer!
n: 3
Enter 0 to stop, any other integer to continue!
ch: 3
Enter integer!
n: 5
Enter 0 to stop, any other integer to continue!
ch: 0
Creating list!
Enter integer!
n: 2
Enter 0 to stop, any other integer to continue!
ch: 2
Enter integer!
n: 4
Enter 0 to stop, any other integer to continue!
ch: 4
Enter integer!
n: 6
Enter 0 to stop, any other integer to continue!
ch: 0
Current Address	Current Data	Next Address
24471728	1		24471824
24471824	2		24471760
24471760	3		24471856
24471856	4		24471792
24471792	5		24471888
24471888	6		0
Enter 1 to display list, 2 to add element, 3 to delete an element, 4 for length, 5 for reverse, 6 for sort, 7 for merge, 8 for erase and 0 to exit!
ch: 0



