#include <iostream>
#include <stdlib.h>

/**
 * Menu driven program to perform basic mathematical operations
 * Keep taking input from the user, until invalid input is entered, then exit
 */

using namespace std;

// Defining Calculator class
class Calculator
{
    // Declaring global variables which will be used by all the methods
    int a, b, result;

    // All the functions defined below will be publicly accessible
    public:
        void sum() // Method to calculate sum of 2 numbers
        {
            result=a+b;
        }

        void difference() // Method to calculate difference between 2 numbers
        {
            result=a-b;
        }

        void product() // Method to calculate product of 2 numbers
        {
            result=a*b;
        }

        void quotient() // Method to calculate quotient of 2 numbers
        {
            if (b==0) { // Check for division by 0, exit if it tries to happen
                cout<<"You can't divide by 0!\n";
                exit(0);
            }
            result=a/b;
        }

        void remainder() // Method to calculate remainder of 2 numbers
        {
            if (b==0) { // Check for division by 0, exit if it tries to happen
                cout<<"You can't divide by 0!\n";
                exit(0);
            }
            result=a%b;
        }

        void input() // Method to prompt the user and accept 2 numbers
        {
            cout<<"Enter 2 numbers!\n";
            cout<<"a: ";
            cin>>a;
            cout<<"b: ";
            cin>>b;
        }

        void display() // Method to display the result to the user
        {
            cout<<"Result is "<<result<<".\n";
        }
};

int main()
{
// Creating object of class Calcualator
Calculator c;

char ch;

do {
    // Prompting the user and accepting input
    cout<<"Options:\n";
    cout<<"+ for addition,\n";
    cout<<"- for subtraction,\n";
    cout<<"* for multiplication,\n";
    cout<<"/ for division,\n";
    cout<<"% for modulus, and\n";
    cout<<"anything else to exit!\n";
    cout<<"choice: ";
    cin>>ch;
    
    // Check the users input with switch-case and call the needed method accordingly
    switch (ch) {
        case '+':
            c.input();
            c.sum();
            c.display();
            break;
        case '-':
            c.input();
            c.difference();
            c.display();
            break;
        case '*':
            c.input();
            c.product();
            c.display();
            break;
        case '/':
            c.input();
            c.quotient();
            c.display();
            break;
        case '%':
            c.input();
            c.remainder();
            c.display();
            break;
        // Default case to exit in the case of an invalid input
        default:
            cout<<"Exiting!\n";
            exit(0);
        }
    } while (1);
}
/*EXECUTION
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ g++ ./calculator.cpp
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ ./a.out
Options:
+ for addition,
- for subtraction,
* for multiplication,
/ for division,
% for modulus, and
anything else to exit!
choice: +
Enter 2 numbers!
a: 5
b: 6
Result is 11.
Options:
+ for addition,
- for subtraction,
* for multiplication,
/ for division,
% for modulus, and
anything else to exit!
choice: *
Enter 2 numbers!
a: 6
b: 4
Result is 24.
Options:
+ for addition,
- for subtraction,
* for multiplication,
/ for division,
% for modulus, and
anything else to exit!
choice: 0
Exiting!
*/
