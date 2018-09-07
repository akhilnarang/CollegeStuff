/*
 * distance.cpp
 *
 *  Created on     : 17-Jul-2018
 *      Author     : Akhil Narang
 *      Roll Number: 203132
 *      Subject    : OOP
 *      Title      : Performing various arithmetical operations on Distance
 *                   values by using the concept of operator overloading
 */

// Include headers required for basic input/output operations
#include <iostream>
using namespace std;

// Define our Distance class
class Distance {

// Declare our private data members
private:
	int kilometers, meters;

// Declare and define our public member methods
public:
	// Parameterized constructor to initialize our Distance number to desired values
	Distance(int kilometers, int meters) {
		this->kilometers=kilometers;
		this->meters=meters;
	}

	// Default constructor to initialize our Distance
	Distance() {
		kilometers=0;
		meters=0;
	}

	// Overload >> operator so that we can easily input Distance type data
	friend istream &operator>>(istream &stdin, Distance &d) {
		cout<<"Enter kilometers: ";
		stdin>>d.kilometers;
		cout<<"Enter meters: ";
		stdin>>d.meters;
		return stdin;
	}

	// Overload << operator so that we can easily display Distance type data
	friend ostream &operator<<(ostream &stdout, Distance d) {
		cout<<d.kilometers<<"km and "<<d.meters<<"m!"<<endl;
		return stdout;
	}

	// Function to add the calling object and the object passed as a parameter and return a third object
	Distance operator+(Distance d) {
		cout<<"Adding!\n";
		int meters = ((d.kilometers*1000) + d.meters) + ((this->kilometers*1000) + this->meters);
		int kilometers = 0;
		if (meters > 1000) {
			kilometers += meters/1000;
			meters %=1000;
		}
		return Distance(kilometers, meters);
	}

	// Function to subtract the object passed as a parameter from the calling object and return a third object
	Distance operator-(Distance d) {
		cout<<"Subtracting!\n";
		int meters = ((d.kilometers*1000) + d.meters) - ((this->kilometers*1000) + this->meters);
		int kilometers = 0;
		if (meters > 1000) {
			kilometers += meters/1000;
			meters %=1000;
		}
		return Distance(kilometers, meters);
	}

	// Function to check if a Distance object is greater than another
	bool operator> (Distance d) {
		int m1 = d.meters + d.kilometers * 1000;
		int m2 = meters + kilometers * 1000;
		return m1 > m2;
	}
};

// Declaring and defining our main function
int main() {
	// Declaring some objects of class Distance
	Distance d1, d2, d3;
	// Prompting the user and accepting input to choose the operation
	int choice;
	cout<<"1 for addition, and  2 for subtraction!"<<endl;
	cout<<"Enter choice: ";
	cin>>choice;
	// Accept 2 Distance numbers with Distance.setDistance() method
	cout<<"Distance 1!"<<endl;
	cin>>d1;
	cout<<"Distance 2!"<<endl;
	cin>>d2;
	// Check users choice using switch-case structure
	switch(choice) {
	case 1:
		d3 = d1 + d2;
		cout<<d3;
		break;
	case 2:
		d3 = d1 > d2 ? d1 - d2 : d2 - d1;
		cout<<d3;
		break;
	default:
		cout<<"Invalid choice!";
	}
	return 0;
}
/* Output:
1 for addition, and  2 for subtraction!
Enter choice: 1
Distance 1!
Enter kilometers: 1
Enter meters: 500
Distance 2!
Enter kilometers: 2
Enter meters: 600
Adding!
4km and 100m!

1 for addition, and  2 for subtraction!
Enter choice: 2
Distance 1!
Enter kilometers: 1
Enter meters: 1500
Distance 2!
Enter kilometers: 2
Enter meters: 800
Subtracting!
0km and 300m!
*/


