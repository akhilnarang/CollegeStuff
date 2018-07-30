/*
 * distance.cpp
 *
 *  Created on: 17-Jul-2018
 *      Author: wpu
 */

// Include headers required for basic input/output operations
#include <iostream>
// Include header for math functions like abs()
#include <cmath>
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

	// Method to accept values from a user and set them as the kilometers and meters of Distance
	void setDistance() {
		cout<<"Enter kilometers: ";
		cin>>kilometers;
		cout<<"Enter meters: ";
		cin>>meters;
	}

	// Method to display a Distance number
	void displayDistance() {
		cout<<kilometers<<"km and "<<meters<<"m!"<<endl;
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
	d1.setDistance();
	d2.setDistance();
	// Check users choice using switch-case structure
	switch(choice) {
	case 1:
		d3 = d1 + d2;
		d3.displayDistance();
		break;
	case 2:
		d3 = d1 > d2 ? d1 - d2 : d2 - d1;
		d3.displayDistance();
		break;
	default:
		cout<<"Invalid choice!";
	}
	return 0;
}
/* Output:
1 for addition, and  2 for subtraction!
Enter choice: 1
Enter kilometers: 1
Enter meters: 500
Enter kilometers: 2
Enter meters: 600
Adding!
4km and 100m!

1 for addition, and  2 for subtraction!
Enter choice: 2
Enter kilometers: 1
Enter meters: 1500
Enter kilometers: 2
Enter meters: 800
Subtracting!
0km and 300m!
*/


