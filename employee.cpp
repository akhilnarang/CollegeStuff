/*
 * employee.cpp
 *
 *  Created on   : 31-Jul-2018
 *      Author   : Akhil Narang
 *      Roll No. : 203132
 *      Subject  : OOP
 */

// Including headers needed for input/output operations and strings
#include <iostream>
#include <string.h>

using namespace std;

// Our base class
class Employee {
public:
	// Public data members of Employee
	string employeeName;
	int employeeId;

	// Default constructor
	Employee() {
		employeeName = "";
		employeeId = 0;
	}

	// Parameterized constructor
	Employee(string employeeName, int employeeId) {
		this->employeeName = employeeName;
		this->employeeId = employeeId;
	}

	// Method to accept data about employee from the user
	void accept() {
		cout<<"Enter employee name: ";
		//cin>>employeeName; cin only accepts one word so we use getline()
		getline(cin, employeeName);
		cout<<"Enter employee id: ";
		cin>>employeeId;
	}

	// Method to display data about employee to the user
	void display() {
		cout<<"Name: "<<employeeName<<endl;
		cout<<"Employee ID: "<<employeeId<<endl;
	}
};

// Derive class from Employee, as virtual so that we can use multiple inheritance
class SalariedEmployee : public virtual Employee {
public:
	// Data member to store salary
	float weeklySalary, salary;

	// Default constructor
	SalariedEmployee() : Employee() {
		weeklySalary = 0;
	}

	// Parameterized constructor
	SalariedEmployee(string employeeName, int employeeId, float weeklySalary) : Employee(employeeName, employeeId) {
		this->weeklySalary = weeklySalary;
	}

	void accept() {
		cout<<"Enter weekly salary: ";
		cin>>weeklySalary;
	}

	void calculateSalary() {
		salary = weeklySalary;
	}

	void display() {
		cout<<"Salary: "<<salary<<endl;
	}
};

class HourlyEmployee : public Employee {
public:
	float wage, salary;
	int hours;

	HourlyEmployee() : Employee() {
		wage = 0;
		hours = 0;
		salary = 0;
	}

	HourlyEmployee(string employeeName, int employeeId, float wage, int hours) : Employee(employeeName, employeeId) {
		this->wage = wage;
		this->hours = hours;
		salary = 0;
	}

	void accept() {
		cout<<"Enter wage: ";
		cin>>wage;
		cout<<"Enter hours: ";
		cin>>hours;
	}

	void calculateSalary() {
		if (hours < 40) {
			salary = wage * hours;
		} else {
			salary = 40 * wage + ((hours - 40) * wage * 1.5);
		}
	}

	void display() {
		cout<<"Wage: "<<wage<<endl;
		cout<<"Hours worked: "<<hours<<endl;
		cout<<"HourlySalary: "<<salary<<endl;
	}
};

class CommissionEmployee : public virtual Employee {
public:
	float sale, rate, salary;

	CommissionEmployee() : Employee() {
		sale = 0;
		rate = 0;
		salary = 0;
	}

	CommissionEmployee(string employeeName, int employeeId, float wage, int hours) : Employee(employeeName, employeeId) {
		this->sale = sale;
		this->rate = rate;
		salary = 0;
	}

	void accept() {
		cout<<"Enter sales: ";
		cin>>sale;
		cout<<"Enter rate: ";
		cin>>rate;
	}

	void calculateSalary() {
		salary = sale * rate/100;
	}

	void display() {
		cout<<"Sales: "<<sale<<endl;
		cout<<"Rate: "<<rate<<endl;
		cout<<"CommissionSalary: "<<salary<<endl;
	}
};

class SalariedCommissionEmployee : public SalariedEmployee, public CommissionEmployee {
public:
	float salary;

	SalariedCommissionEmployee() : SalariedEmployee(), CommissionEmployee() {
		salary = 0;
	}

	SalariedCommissionEmployee(float salary) : SalariedEmployee(), CommissionEmployee() {
		this->salary = salary;
	}

	void calculateSalary() {
		salary = SalariedEmployee::salary + CommissionEmployee::salary;
	}

	void display() {
		cout<<"Weekly+Commission salary: "<<salary;
	}

};

int main() {
	int ch;
	cout<<"1. Salaried Employee"<<endl;
	cout<<"2. Hourly Employee"<<endl;
	cout<<"3. Commission Employee"<<endl;
	cout<<"4. Salaried Commission Employee"<<endl;
	cout<<"Enter choice: ";
	cin>>ch;
	cin.ignore(100000, '\n');
	switch (ch) {
	case 1: {
		cout<<"SALARIED EMPLOYEE"<<endl;
		SalariedEmployee s;
		s.Employee::accept();
		cin.ignore(100000, '\n');
		s.accept();
		s.Employee::display();
		s.calculateSalary();
		s.display();
	} break;
	case 2: {
		cout<<"HOURLY EMPLOYEE"<<endl;
		HourlyEmployee h;
		h.Employee::accept();
		cin.ignore(100000, '\n');
		h.accept();
		h.Employee::display();
		h.calculateSalary();
		h.display();
	} break;
	case 3: {
		cout<<"Commission EMPLOYEE"<<endl;
		CommissionEmployee c;
		c.Employee::accept();
		cin.ignore(100000, '\n');
		c.accept();
		c.Employee::display();
		c.calculateSalary();
		c.display();
	} break;
	case 4: {
		cout<<"SALARIED Commission EMPLOYEE"<<endl;
		SalariedCommissionEmployee sc;
		sc.Employee::accept();
		cin.ignore(100000, '\n');
		sc.SalariedEmployee::accept();
		sc.CommissionEmployee::accept();
		sc.Employee::display();
		sc.SalariedEmployee::calculateSalary();
		sc.SalariedEmployee::display();
		sc.CommissionEmployee::calculateSalary();
		sc.CommissionEmployee::display();
		sc.calculateSalary();
		sc.display();
	} break;
	default:
		cout<<"Invalid input!"<<endl;
	}
	return 0;
}
