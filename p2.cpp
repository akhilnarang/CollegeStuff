/*
 * p2.cpp
 *
 *  Created on: 10-Jul-2018
 *      Author: wpu
 */
#include <iostream>

using namespace std;

class Complex {
    int real, imaginary;

   public:
    Complex(int r, int i) {
        real = r;
        imaginary = i;
    }

    Complex() {
        real = 0;
        imaginary = 0;
    }
    void setComplex() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }

    void displayComplex() {
        cout << "Complex number is: ";
        if (imaginary >= 0) {
            cout << real << "+" << imaginary << "i!\n";
        } else {
            cout << real << imaginary << "i!\n";
        }
    }

    Complex add(Complex c) {
        cout << "Adding!\n";
        real += c.real;
        imaginary += c.imaginary;
        return Complex(real, imaginary);
    }

    Complex subtract(Complex c) {
        cout << "Subtracting!\n";
        real = real - c.real;
        imaginary = imaginary - c.imaginary;
        return Complex(real, imaginary);
    }

    Complex multiply(Complex c) {
        cout << "Multiplying!\n";
        return Complex(real * c.real - imaginary * c.imaginary,
                       real * c.imaginary + c.real * imaginary);
    }
};

int main() {
    Complex c1, c2, c3;
    int choice;
    cout << "1 for addition, 2 for subtraction, 3 for multiplication!\n";
    cout << "Enter choice: ";
    cin >> choice;
    c1.setComplex();
    c2.setComplex();
    switch (choice) {
        case 1:
            c3 = c1.add(c2);
            c3.displayComplex();
            break;
        case 2:
            c3 = c1.subtract(c2);
            c3.displayComplex();
            break;
        case 3:
            c3 = c1.multiply(c2);
            c3.displayComplex();
            break;
        default:
            cout << "Invalid choice!";
    }
    return 0;
}
