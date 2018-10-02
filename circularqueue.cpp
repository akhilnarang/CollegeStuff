/*
 * circularqueue.cpp
 *
 *  Created on: 02-Oct-2018
 *      Author: Zeeshan Hussain
 *      Circular Queue implementation using array and template
 */

// Including header for input/output operations
#include <iostream>

using namespace std;

// Declaring a template for us to use, so that our queue can be of any data type
template <typename T>
class Queue
{
    // Size of our queue (array)
    const static int size = 4;

    // Variable to hold the rear and front position in the queue
    int rear, front;

    // Our queue, of type T
    T t[size];

  public:
    // Constructor to initialize the front and rear
    Queue()
    {
        rear = -1;
        front = -1;
    }

    // Method to push elements onto the queue
    void enqueue()
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full! Cannot push more!\n";
            return;
        }
        T n;
        cout << "Enter value to be pushed: ";
        cin >> n;
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        t[rear] = n;
    }

    // Method to pop elements from the front of the queue
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty! Cannot pop more!\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    // Method to display the elements in the stack
    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty!\n";
            return;
        }
        int count, i;
        if (front > rear)
        {
            count = rear + (size - front) + 1;
        }
        else
        {
            count = (rear - front) + 1;
        }
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % size;
            cout << t[index] << endl;
        }
    }
};
template <typename T>
void stuff(Queue<T> q)
{
    int ch;
    do
    {
        // Prompt the user and accept choice, accordingly call function
        cout << "Enter 1 to push, 2 to pop, 3 to display, and 4 to exit!\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting!\n";
            break;
        default:
            cout << "Wrong input!\n";
        }
    } while (ch != 4); // Only run as long as choice is not exit
}

// main function declaration
int main()
{
    cout << "Enter 1 for Integer, 2 for Character, and 3 for Double type "
            "data!\n";
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        Queue<int> q;
        stuff(q);
        break;
    }
    case 2:
    {
        Queue<char> q;
        stuff(q);
        break;
    }
    case 3:
    {
        Queue<double> q;
        stuff(q);
        break;
    }
    default:
        cout << "Wrong choice!\n";
    }

    return 0;
}