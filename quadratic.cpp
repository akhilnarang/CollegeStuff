/*
 * quadratic.cpp
 *
 *  Created on: 17-Jul-2018
 *      Author: wpu
 */

// Include headers required for basic input/output operations
#include <iostream>
using namespace std;
// Define our Quadratic class
class Quadratic {

// Declare our private data members
private:
	int a, b, c;

// Declare and define our public member methods
public:
	Quadratic(); // Default constructor
	Quadratic(int, int, int); // Parameterized constructor
	Quadratic operator+(Quadratic); // Function to add caller and parameter
	Quadratic operator-(Quadratic); // Function to subtract parameter from caller
	void accept(); // Function to accept 3 numbers for a quadratic equation
	void display(); // Function to display quadratic equation
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
	cout<<"Adding 2 quadratic equations!"<<endl;
	int a = q.a + this->a;
	int b = q.b + this->b;
	int c = q.c + this->c;
	return Quadratic(a, b, c);
}

Quadratic Quadratic::operator-(Quadratic q) {
	cout<<"Subtracting 2 quadratic equations!"<<endl;
	int a = q.a - this->a;
	int b = q.b - this->b;
	int c = q.c - this->c;
	return Quadratic(a, b, c);
}

void Quadratic::accept() {
	cout<<"Enter values for quadratic equation!"<<endl;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	cout<<"c: ";
	cin>>c;
}

void Quadratic::display() {
	cout<<"Quadratic equation is:"<<endl;
	cout<<a<<"x^2";
	if (b>=0) {
		cout<<"+";
	}
	cout<<b<<"x";
	if (c>=0) {
		cout<<"+";
	}
	cout<<c<<endl;
}

// Declaration and definition of main()
int main() {
	// Create objects of Quadratic class
	Quadratic q1, q2, q3;
	// Call the functions in order to accept 2 equations, add and subtract them and display the result each time
	q1.accept();
	q2.accept();
	q1.display();
	q2.display();
	q3 = q1 + q2;
	q3.display();
	q3 = q1 - q2;
	q3.display();
	return 0;
}

/* OUTPUT
Enter values for quadratic equation!
a: 5
b: 5
c: 5
Enter values for quadratic equation!
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
