/*
 * stack.cpp
 *
 *  Created on: 11-Sep-2018
 *      Author: Akhil Narang
 *      Roll No. 203132
 *      Stack implementation using array and template
 */

// Including header for input/output operations
#include<iostream>

using namespace std;

// Declaring a template for us to use, so that our stack can be of any data type
template <typename T>
class Stack {
	// Size of our stack (array)
	const static int size = 4;
	// Variable to hold the current position in the stack
	int top;
	// Our stack, of type T
	T t[size];

public:
	// Constructor to initialize the top
	Stack() {
		top=-1;
	}

	// Method to push elements onto the stack
	void push() {
		if (top == size) {
			cout << "Stack is full! Cannot push more!\n";
			return;
		}
		T n;
		cout << "Enter value to be pushed: ";
		cin >> n;
		top++;
		t[top] = n;
	}

	// Method to pop elements from the top of the stack
	void pop() {
		if (top == -1) {
			cout << "Stack is empty! Cannot pop more!\n";
			return;
		}
		top--;
	}

	// Method to display the elements in the stack
	void display() {
		for (int i = top;i > -1;i--) {
			cout<<t[i]<<endl;
		}
	}

};

// template so that user can choose the stack's type
template <typename T>
void stuff(Stack<T> s) {
	int ch;
	do {
		// Prompt the user and accept choice, accordingly call function
		cout << "Enter 1 to push, 2 to pop, 3 to display, and 4 to exit!\n";
		cin >> ch;
		switch (ch) {
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.display();
			break;
		case 4:
			cout<<"Exiting!\n";
			break;
		default:
			cout<<"Wrong input!\n";
		}
	} while (ch != 4); // Only run as long as choice is not exit
}

// main function declaration
int main() {
	cout<<"Enter 1 for Integer, 2 for Character, and 3 for Double type data!\n";
	cout<<"Enter your choice: ";
	int ch;
	cin>>ch;
	switch (ch) {
	case 1: {
		Stack<int> s;
		stuff(s);
		break;
	}
	case 2: {
		Stack<char> s;
		stuff(s);
		break;
	}
	case 3: {
		Stack<double> s;
		stuff(s);
		break;
	}
	default:
		cout<<"Wrong choice!\n";
	}

	return 0;
}