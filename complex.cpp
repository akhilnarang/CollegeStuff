/*
 * complex.cpp
 *
 *  Created on: 10-Jul-2018
 *      Author: wpu
 */

// Include headers required for basic input/output operations
#include <iostream>
using namespace std;

// Define our Complex class
class Complex {

// Declare our private data members
private:
	int real, imaginary;

// Declare and define our public member methods
public:
	// Parameterized constructor to initialize our Complex number to desired values
	Complex(int real, int imaginary) {
		this->real=real;
		this->imaginary=imaginary;
	}

	// Default constructor to initialize our Complex number to 0+0i
	Complex() {
		real=0;
		imaginary=0;
	}

	// Method to accept values from a user and set them as the real and imaginary part of a complex number
	void setComplex() {
		cout<<"Enter real part: ";
		cin>>real;
		cout<<"Enter imaginary part: ";
		cin>>imaginary;
	}

	// Method to display a Complex number
	void displayComplex() {
		cout<<"Complex number is: ";
		// Check for negative cases and display + or - accordingly
		if (imaginary>=0) {
			cout<<real<<"+"<<imaginary<<"i!\n";
		} else {
			cout<<real<<imaginary<<"i!\n";
		}

	}

	// Function to add the calling object and the object passed as a parameter and return a third object
	Complex operator+(Complex c) {
		cout<<"Adding!\n";
		int real = this->real + c.real;
		int imaginary = this->imaginary + c.imaginary;
		return Complex(real, imaginary);
	}

	// Function to subtract the object passed as a parameter from the calling object and return a third object
	Complex operator-(Complex c) {
		cout<<"Subtracting!\n";
		int real = this->real - c.real;
		int imaginary = this->imaginary - c.imaginary;
		return Complex(real, imaginary);
	}
	// Function to multiply the calling object and the object passed as a parameter and return a third object
	Complex operator*(Complex c) {
		cout<<"Multiplying!\n";
		return Complex(real*c.real-imaginary*c.imaginary, real*c.imaginary+c.real*imaginary);
	}
};

// Declaring and defining our main function
int main() {
	// Declaring some objects of class Complex
	Complex c1, c2, c3;
	// Prompting the user and accepting input to choose the operation
	int choice;
	cout<<"1 for addition, 2 for subtraction, 3 for subtraction (the other way) and 4 for multiplication!\n";
	cout<<"Enter choice: ";
	cin>>choice;
	// Accept 2 complex numbers with Complex.setComplex() method
	c1.setComplex();
	c2.setComplex();
	// Check users choice using switch-case structure
	switch(choice) {
	case 1:
		c3=c1+c2;
		c3.displayComplex();
		break;
	case 2:
		c3=c1-c2;
		c3.displayComplex();
		break;
	case 3:
		c3=c2-c1;
		c3.displayComplex();
		break;
	case 4:
		c3=c1*c2;
		c3.displayComplex();
		break;
	default:
		cout<<"Invalid choice!";
	}
	return 0;
}

/* Output:
1 for addition, 2 for subtraction, 3 for subtraction (the other way) and 4 for multiplication!
Enter choice: 1
Enter real part: 2
Enter imaginary part: 3
Enter real part: 2
Enter imaginary part: 3
Adding!
Complex number is: 4+6i!

1 for addition, 2 for subtraction, 3 for subtraction (the other way) and 4 for multiplication!
Enter choice: 4
Enter real part: 2
Enter imaginary part: 3
Enter real part: 4
Enter imaginary part: 5
Multiplying!
Complex number is: -7+22i!
*/

