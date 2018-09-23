#include <stdlib.h>
#include <iostream>

/**
 * Menu driven program to perform operations on complex numbers
 * Create a different object for each complex number
 * Also add a destructor to destroy the objects
 */

using namespace std;

class Complex {
    // Member variables of class Complex to hold real and imaginary parts of
    // complex number
    int real, imaginary;

   public:
    Complex()  // Default constructor, initializes everything to 0
    {
        real = imaginary = 0;
    }
    Complex(
        int r,
        int i)  // Parametrized constructor to initialize the member variables
    {
        real = r;
        imaginary = i;
    }
    Complex add(Complex* c)  // Method to add the complex numbers and return an
                             // object of class Complex which contains sum
    {
        return Complex(c->real + this->real, c->imaginary + this->imaginary);
    }
    Complex subtract(
        Complex* c)  // Method to subtract the complex numbers and return an
                     // object of class Complex which contains the difference
    {
        return Complex(c->real - this->real, c->imaginary - this->imaginary);
    }
    void display()  // Method to display the the complex number stored in the
                    // calling object
    {
        cout << "\nReal part " << this->real << "\nImaginary part "
             << this->imaginary << "\n\n";
    }
    ~Complex()  // Destructor for class Complex
    {
        cout << "Destroying object " << this << "!\n";
    }
};

int main() {
    int real, imaginary;
    // Declaration of variables, prompting user, and accepting input and
    // creation of 2 objects of class Complex
    cout << "\nEnter values for complex number 1!\n";
    cout << "Real: ";
    cin >> real;
    cout << "Imaginary: ";
    cin >> imaginary;
    Complex c1(real, imaginary);

    cout << "\nEnter values for complex number 2!\n";
    cout << "Real: ";
    cin >> real;
    cout << "Imaginary: ";
    cin >> imaginary;
    Complex c2(real, imaginary);

    // Prompt and take choice as input
    cout << "\nEnter 1 for addition,\n2 for subtraction(first from second)\n3 "
            "for substraction(second from first), and\nanything else to exit: ";
    int c;
    cin >> c;
    switch (
        c) {  // switch-case structure to check user's choice, accordingly
              // create an object, call the required method, and display output
        case 1: {
            cout << "\nSum is: ";
            Complex c3 = c1.add(&c2);
            c3.display();
            break;
        }
        case 2: {
            cout << "\nDifference is: ";
            Complex c3 = c1.subtract(&c2);
            c3.display();
            break;
        }
        case 3: {
            cout << "\nDifference is: ";
            Complex c3 = c2.subtract(&c1);
            c3.display();
            break;
        }
        default:
            exit(0);  // Exit on wrong input
    }
}
/*EXECUTION
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ g++ ./complex_constructor.cpp
fpllab@fpllab-OptiPlex-9020:~/Desktop/Akhil$ ./a.out

Enter values for complex number 1!
Real: 8
Imaginary: 9

Enter values for complex number 2!
Real: 6
Imaginary: 7

Enter 1 for addition,
2 for subtraction(first from second)
3 for substraction(second from first), and
anything else to exit: 1

Sum is:
Real part 14
Imaginary part 16

Destroying object 0x7ffd67b72140!
Destroying object 0x7ffd67b72130!
Destroying object 0x7ffd67b72120!
*/
