#include <iostream>
#include <cstdlib>

/**
 * Menu driven program to perform basic mathematical operations
 */

using namespace std;

// Defining Calculator class
class Calculator
{
    // Declaring global variables which will be used by all the methods
    int a, b, result;

    // All the below functions will be publicly accessible
    public:
        void sum()
        {
            // Method to calculate sum of 2 numbers
            result=a+b;
        }

        void difference()
        {
            // Method to calculate difference between 2 numbers
            result=a-b;
        }

        void product()
        {
            // Method to calculate product of 2 numbers
            result=a*b;
        }

        void quotient()
        {
            // Method to calculate quotient of 2 numbers
            if (b==0) { // Check for division by 0, exit if it tries to happen
                cout<<"You can't divide by 0!\n";
                exit(0);
            }
            result=a/b;
        }

        void remainder()
        {
            // Method to calculate remainder of 2 numbers
            if (b==0) { // Check for division by 0, exit if it tries to happen
                cout<<"You can't divide by 0!\n";
                exit(0);
            }
            result=a%b;
        }

        void input()
        {
            // Method to prompt the user and accept 2 numbers
            cout<<"Enter 2 numbers!\n";
            cout<<"a: ";
            cin>>a;
            cout<<"b: ";
            cin>>b;
        }

        void display()
        {
            // Method to display the result to the user
            cout<<"Result is "<<result<<".\n";
        }
};

int main()
{
Calculator c; // Creating object of class Calcualator

char ch;

// Calling input() method using the object c of Calculator
c.input();

// Prompting the user and accepting input
cout<<"Options:\n";
cout<<"+ for addition,\n";
cout<<"- for subtraction,\n";
cout<<"* for multiplication,\n";
cout<<"/ for division, and\n";
cout<<"% for modulus!\n";
cout<<"choice: ";
cin>>ch;

// Check the users input with switch-case and call the needed method accordingly
switch (ch) {
    case '+':
        c.sum();
        c.display();
        break;
    case '-':
        c.difference();
        c.display();
        break;
    case '*':
        c.product();
        c.display();
        break;
    case '/':
        c.quotient();
        c.display();
        break;
    case '%':
        c.remainder();
        c.display();
        break;
    // Default case to tell the user in the case of an invalid input
    default:
        cout<<"Invalid choice\n";
    }
}
