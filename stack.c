/*
 * stack.c
 *
 *      Author: Akhil Narang
 * Roll Number: 203132
 */

#include <stdio.h>
#include <string.h>

int size=50;
int top=-1;
int topM=-1;

int push(char n, char st[])
{

	if(top+1 < size) {
		st[++top] = n;
		return 1;
	}
	return 0;
}

int pushMultiple(char s[], char stk[][50])
{
	if(topM+1 < size) {
		strcpy(stk[++topM], s);
		return 1;
	}
	return 0;
}

char pop(char st[])
{
	char temp = '\0';
	if(top >= 0) {
		temp = st[top];
		st[top--] = '\0';
	}
	return temp;
}


int popMultiple(char st[][50], char ret[])
{

	if(topM >= 0) {
		strcpy(ret, st[topM]);
		st[topM--][0] = '\0';
		return 1;
	}

	return 0;

}

int isp(char c)
{

	if(c == '+' || c == '-') {
		return 1;
	}
	else if(c == '*' || c == '/') {
		return 2;
	}
	else if(c == '^') {
		return 3;
	}

	return 0;
}

int icp(char c)
{

	if(c == '+' || c == '-') {
		return 1;
	}
	else if(c == '*' || c == '/') {
		return 2;
	}
	else if(c == '^') {
		return 4;
	}

	return 0;
}

void inToPost(char expression[], char convExpression[], char st[])
{

	int n = 0, m = 0;
	char c = '\0';

	while(expression[n] != '\0') {

		if(icp(expression[n])) {
			if(top != -1 && isp(st[top]) >= icp(expression[n])) {
				c = pop(st);
				push(expression[n], st);
				convExpression[m++] = c;
			}
			else {
				push(expression[n], st);
			}
		}

		else if(expression[n] == '(') {
			push(expression[n], st);	
		}

		else if(expression[n] == ')') {
			while((c = pop(st)) != '(') {	
				convExpression[m++] = c;	
			}
		}

		else {
			convExpression[m++] = expression[n];	
		}

		n++;	

	}

	while(top>=0) {
		convExpression[m++] = pop(st);	
	}

	convExpression[m] = '\0';	

}


void preToPost(char expression[], char stk[][50]) {

	char op1[50], op2[50];	
	char ch[2];	ch[1] = '\0';	
	int n = strlen(expression) - 1;	

	while(n>=0) {	

		if(icp(expression[n])) {
			ch[0] = expression[n];
			popMultiple(stk, op1);
			popMultiple(stk, op2);
			strcat(op1,op2);
			strcat(op1,ch);
			pushMultiple(op1, stk);
		}

		else if(expression[n] == '(' || expression[n] == ')') {
			
		}

		else {
			ch[0] = expression[n];
			pushMultiple(ch, stk);
		}

		n--;

	}

}

void postToPre(char expression[], char stk[][50])
{

	char op1[50], op2[50];
	char ch[2];
	ch[1] = '\0';
	int n = 0;

	while(expression[n] != '\0') {

		if(icp(expression[n])) {
			ch[0] = expression[n];
			popMultiple(stk, op2);
			popMultiple(stk, op1);
			strcat(ch,op1);
			strcat(ch,op2);
			pushMultiple(ch, stk);
		}

		else if(expression[n] == '(' || expression[n] == ')') {
			
		}

		else{
			ch[0] = expression[n];
			pushMultiple(ch, stk);
		}

		n++;

	}

}

int main() {

	char st[50];
	char stk[50][50];

	char expression[50];
	char convExpression[50];

	int choice = 1;

	do {

		printf("1. Infix to Postfix\n2. Prefix to Postfix\n3. Postfix to Prefix\n");
		printf("choice: ");
		scanf("%d", &choice);

		switch(choice) {

		case 1:		printf("Enter an infix expression!\n");
				printf("expression: ");
				scanf("%s", expression);
				inToPost(expression, convExpression, st);
				printf("\nthe infix expression in postfix form is :\n%s\n", convExpression);
				break;

		case 2: 	printf("Enter a prefix expression!\n");
				printf("expression: ");
				scanf("%s", expression);
				preToPost(expression, stk);
				popMultiple(stk, convExpression);
				printf("The prefix expression in postfix form is: %s\n", convExpression);
				break;

		case 3:		printf("Enter an postfix expression!\n");
				scanf("%s", expression);
				postToPre(expression, stk);
				popMultiple(stk, convExpression);
				printf("The postfix expression in prefix form is: %s\n", convExpression);
				break;

		default:	printf("Invalid choice\n");
				break;

		}

		printf("Enter 0 to exit!\n");
		printf("choice: ");
		scanf("%d", &choice);

	} while(choice);

}


