#include <iostream>
#include <stdlib.h>

/**
 * Menu driven program to perform operations on complex numbers
 * Create a different object for each complex number
 * Also add a destructor to destroy the objects
 */

using namespace std;

class Complex
{
    // Member variables of class Complex to hold real and imaginary parts of complex number
    int real, imaginary;
    
    public:
        Complex() // Default constructor
        {
            real=imaginary=0;
        }
        Complex(int r, int i) // Parametrized constructor to initialize the member variables
        {
            real=r;
            imaginary=i;
        }
        Complex add(Complex *c) // Method to add the complex numbers and return the object which contains the result
        {
            return Complex(c->real+this->real, c->imaginary+this->imaginary);
        }
        Complex subtract(Complex *c) // Method to subtract the complex numbers and return the object which contains the result
        {
            return Complex(c->real-this->real, c->imaginary-this->imaginary);
        }
        void display() // Method to display the result
        {
            cout<<"\n\nResult:- \nReal part "<<this->real<<"\nImaginary part "<<this->imaginary<<"\n\n\n";
        }
        ~Complex() // Destructor for class Complex
        {
            cout<<"Destroying object "<<this<<"!\n";
        }
};

int main()
{
    int real, imaginary;
    // Declaration of variables, prompting user, and accepting input
    cout<<"\n\nEnter values for complex number 1!\n";
    cout<<"Real: ";
    cin>>real;
    cout<<"Imaginary: ";
    cin>>imaginary;
    Complex c1(real, imaginary);

    cout<<"\n\nEnter values for complex number 2!\n";
    cout<<"Real: ";
    cin>>real;
    cout<<"Imaginary: ";
    cin>>imaginary;
    Complex c2(real, imaginary);

    // Prompt and take choice as input
    cout<<"\n\nEnter 1 for addition,\n2 for subtraction(first from second)\n3 for substraction(second from first), and\nanything else to exit: ";
    int c;
    cin>>c;
    Complex c3;
    switch (c) { // switch-case structure to check user's choice
        case 1: c3=c1.add(&c2); break;
        case 2: c3=c1.subtract(&c2); break;
        case 3: c3=c2.subtract(&c1); break;
        default: exit(0); // Exit on wrong input
    }
    c3.display(); // Call display() of class Complex to show the result
}
