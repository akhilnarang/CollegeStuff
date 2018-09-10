/*
 * quadratic.cpp
 *
 *  Created on     : 17-Jul-2018
 *      Author     : Akhil Narang
 *      Roll Number: 203132
 *      Subject    : OOP
 *      Title      : Performing various arithmetical operations on Quadratic
 *                   numbers by using the concept of operator overloading
 */

// Include headers required for basic input/output operations
#include <iostream>
using namespace std;
// Define our Quadratic class
class Quadratic {

    // Declare and define our public data members and member methods
  public:
    int a, b, c;
    Quadratic();                    // Default constructor
    Quadratic(int, int, int);       // Parameterized constructor
    Quadratic operator+(Quadratic); // Function to add caller and parameter
    Quadratic
    operator-(Quadratic); // Function to subtract parameter from caller
    friend istream& operator<<(istream stdin, Quadratic q);
    friend istream& operator>>(ostream stdout, Quadratic q);
};

// Defining the constructors and methods of class Complex

Quadratic::Quadratic() {
    a = 0;
    b = 0;
    c = 0;
}

Quadratic::Quadratic(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

Quadratic Quadratic::operator+(Quadratic q) {
    cout << "Adding 2 quadratic equations!" << endl;
    int a = q.a + this->a;
    int b = q.b + this->b;
    int c = q.c + this->c;
    return Quadratic(a, b, c);
}

Quadratic Quadratic::operator-(Quadratic q) {
    cout << "Subtracting 2 quadratic equations!" << endl;
    int a = q.a - this->a;
    int b = q.b - this->b;
    int c = q.c - this->c;
    return Quadratic(a, b, c);
}

// Overload >> operator so that we can easily input Quadratic type data
istream& operator>>(istream& stdin, Quadratic& q) {
    cout << "a: ";
    stdin >> q.a;
    cout << "b: ";
    stdin >> q.b;
    cout << "c: ";
    stdin >> q.c;
    return stdin;
}

// Overload << operator so that we can easily display Quadratic type data
ostream& operator<<(ostream& stdout, Quadratic q) {
    stdout << "Quadratic equation is:" << endl;
    stdout << q.a << "x^2";
    if (q.b >= 0) {
        stdout << "+";
    }
    stdout << q.b << "x";
    if (q.c >= 0) {
        stdout << "+";
    }
    stdout << q.c << endl;
    return stdout;
}

// Declaration and definition of main()
int main() {
    // Create objects of Quadratic class
    Quadratic q1, q2, q3;
    // Call the functions in order to accept 2 equations, add and subtract them
    // and display the result each time
    cout << "Enter values for quadratic equation 1!" << endl;
    cin >> q1;
    cout << "Enter values for quadratic equation 2!" << endl;
    cin >> q2;
    cout << q1;
    cout << q2;
    q3 = q1 + q2;
    cout << q3;
    q3 = q1 - q2;
    cout << q3;
    return 0;
}

/* OUTPUT
Enter values for quadratic equation 1!
a: 5
b: 5
c: 5
Enter values for quadratic equation 2!
a: 4
b: 4
c: 4
Quadratic equation is:
5x^2+5x+5
Quadratic equation is:
4x^2+4x+4
Adding 2 quadratic equations!
Quadratic equation is:
9x^2+9x+9
Subtracting 2 quadratic equations!
Quadratic equation is:
-1x^2-1x-1
*/
