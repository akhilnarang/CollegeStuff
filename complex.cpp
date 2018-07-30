/*
 * complex.cpp
 *
 *  Created on     : 10-Jul-2018
 *      Author     : Akhil Narang
 *      Roll Number: 203132
 *      Subject    : OOP
 *      Title      : Performing various arithmetical operations on Complex
 *                   numbers by using the concept of operator overloading
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

	// Overload >> operator so that we can easily input Complex type data
	istream &operator>>(istream &stdin) {
		cout<<"Real part: ";
		stdin>>this->real;
		cout<<"Imaginary part: ";
		stdin>>this->imaginary;
		return stdin;
	}

	// Overload << operator so that we can easily display Complex type data
	ostream &operator<<(ostream &stdout) {
		cout<<"Complex number is: ";
		// Check for negative cases and display + or - accordingly
		if (this->imaginary>=0) {
			stdout<<this->real<<"+"<<this->imaginary<<"i!\n";
		} else {
			stdout<<this->real<<this->imaginary<<"i!\n";
		}
		return stdout;
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
	// Accept 2 complex numbers with overloaded << operator method
	cout<<"Enter complex number 1!"<<endl;
	c1>>cin;
	cout<<"Enter complex number 2!"<<endl;
	c2>>cin;
	// Check users choice using switch-case structure
	switch(choice) {
	case 1:
		c3=c1+c2;
		c3<<cout;
		break;
	case 2:
		c3=c1-c2;
		c3<<cout;;
		break;
	case 3:
		c3=c2-c1;
		c3<<cout;
		break;
	case 4:
		c3=c1*c2;
		c3<<cout;
		break;
	default:
		cout<<"Invalid choice!";
	}
	return 0;
}

/* Output:
1 for addition, 2 for subtraction, 3 for subtraction (the other way) and 4 for multiplication!
Enter choice: 1
Enter complex number 1!
Real part: 2
Imaginary part: 3
Enter complex number 2!
Real part: 2
Imaginary part: 3
Adding!
Complex number is: 4+6i!

1 for addition, 2 for subtraction, 3 for subtraction (the other way) and 4 for multiplication!
Enter choice: 4
Enter complex number 1!
Real part: 2
Imaginary part: 3
Enter complex number 2!
Real part: 4
Imaginary part: 5
Multiplying!
Complex number is: -7+22i!
*/
