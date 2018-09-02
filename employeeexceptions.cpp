/*
 * employeeexceptions.cpp
 *
 *  Created on   : 21-Aug-2018
 *      Author   : Akhil Narang
 *      Roll No. : 203132
 *      Subject  : OOP
 */

// Including headers needed for input/output operations and strings

#include <iostream>
#include <string.h>
using namespace std;

// Defining our class
class EmployeeExceptions {
// Public access for our data members and member methods
public:
	int employee_id, age;
	string name, city;
	float salary;
	char vehicle;

	// Default constructor
	EmployeeExceptions() {
		employee_id = age = salary = 0;
		name = city = "";
		vehicle = '\0';
	}

	// Parameterized constructor
	EmployeeExceptions(int employee_id, string name, int age, float salary,
			string city, char vehicle) {
		this->employee_id = employee_id;
		this->name = name;
		this->age = age;
		this->salary = salary;
		this->city = city;
		this->vehicle = vehicle;
	}

	// Display method to show us the details of employee
	void display() {
		cout<<"Name: "<<name<<endl;
		cout<<"EmployeeExceptions ID: "<<employee_id<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Salary: "<<salary<<endl;
		cout<<"City: "<<city<<endl;
		cout<<"Vehicle: "<<vehicle<<endl;
	}
};

// main function
int main() {
	int count;
	int employee_id, age;
	string name, city;
	float salary;
	char vehicle;
	// Prompt user and accept values
	cout<<"Enter name: ";
	getline(cin, name);
	cout<<"Enter Employee id: ";
	cin>>employee_id;
	cout<<"Enter age: ";
	cin>>age;
	cout<<"Enter income: ";
	cin>>salary;
	cout<<"Enter city: ";
	cin>>city;
	cout<<"Enter y for 4 wheeler else n: ";
	cin>>vehicle;
	// try-catch blocks to check for valid data
	try {
		if (age < 18 || age > 55) {
			throw age;
		} else {
			count++;
		}
	} catch (int n) {
		cout<<"Exception caught. Invalid age"<<n;
		cout<<"!\nShould be within range 18-55!\n";
	}
	try {
		if (salary < 50000 || salary > 100000) {
			throw salary;
		} else {
			count++;
		}
	} catch (float n) {
		cout<<"Exception caught. Invalid salary"<<n;
		cout<<"!\nShould be within range 50000 - 100000!\n";
	}
	bool valid = false;
	try {
		// Create an array of cities to make the check easier
		string valid_cities[] = { "Pune", "Bangalore", "Mumbai" , "Chennai" };
		for (int i=0; i<4; i++) {
			int diff = city.compare(valid_cities[i]);
			/* Check for uppercase and lowercase, if user has entered all
			 lowercase then the difference will be 32 */
			if (diff == 0 || diff == 32) {
				valid = true;
				// Break out if it matches a valid city after setting a flag accordingly
				break;
			}
		}
		if (!valid) {
			throw city;
		} else {
			count++;
		}
	} catch (string s) {
		cout<<"Exception caught. Invalid city "<<city<<"!";
		cout<<"\nShould be one of Pune|Bangalore|Mumbai|Chennai\n";
	}

	try {
		if (vehicle != 'y' && vehicle != 'Y') {
			throw vehicle;
		} else {
			count++;
		}
	}
	catch (char c) {
		cout<<"Exception caught, you must have a 4 wheeler!\n";
	}

	// If all 4 values are valid, then create an object and call the display() function
	if(count == 4) {
		EmployeeExceptions e(employee_id, name, age, salary, city, vehicle);
		e.display();
	}
}
