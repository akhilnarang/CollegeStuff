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
#include <string>

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
	// Data members to store salary
	float weeklySalary, salary;

	// Default constructor
	SalariedEmployee() : Employee() {
		weeklySalary = 0;
		salary = 0;
	}

	// Parameterized constructor
	SalariedEmployee(string employeeName, int employeeId, float weeklySalary) : Employee(employeeName, employeeId) {
		this->weeklySalary = weeklySalary;
		salary = 0;
	}

	// Method to accept required data from the user
	void accept() {
		cout<<"Enter weekly salary: ";
		cin>>weeklySalary;
	}

	// Method to calculate the salary
	void calculateSalary() {
		salary = weeklySalary;
	}

	// Method to display the salary
	void display() {
		cout<<"Salary: "<<salary<<endl;
	}
};

// Derive class from Employee
class HourlyEmployee : public Employee {
public:

	// Data members to store the wages, salary, hours worked
	float wage, salary;
	int hours;

	// Default constructor
	HourlyEmployee() : Employee() {
		wage = 0;
		hours = 0;
		salary = 0;
	}

	// Parameterized constructor
	HourlyEmployee(string employeeName, int employeeId, float wage, int hours) : Employee(employeeName, employeeId) {
		this->wage = wage;
		this->hours = hours;
		salary = 0;
	}

	// Method to accept required data from the user
	void accept() {
		cout<<"Enter wage: ";
		cin>>wage;
		cout<<"Enter hours: ";
		cin>>hours;
	}

	// Method to calculate the salary
	void calculateSalary() {
		if (hours < 40) {
			salary = wage * hours;
		} else {
			salary = 40 * wage + ((hours - 40) * wage * 1.5);
		}
	}

	// Method to display the salary
	void display() {
		cout<<"Wage: "<<wage<<endl;
		cout<<"Hours worked: "<<hours<<endl;
		cout<<"HourlySalary: "<<salary<<endl;
	}
};

// Derive class from Employee, as virtual so that we can use multiple inheritance
class CommissionEmployee : public virtual Employee {
public:

	// Data members to store the sales, rate, and salary
	float sale, rate, salary;

	// Default constructor
	CommissionEmployee() : Employee() {
		sale = 0;
		rate = 0;
		salary = 0;
	}

	// Parameterized constructor
	CommissionEmployee(string employeeName, int employeeId, float wage, int hours) : Employee(employeeName, employeeId) {
		this->sale = sale;
		this->rate = rate;
		salary = 0;
	}

	// Method to accept required data from the user
	void accept() {
		cout<<"Enter sales: ";
		cin>>sale;
		cout<<"Enter rate: ";
		cin>>rate;
	}

	// Method to calculate the salary
	void calculateSalary() {
		salary = sale * rate/100;
	}

	// Method to display the salary
	void display() {
		cout<<"Sales: "<<sale<<endl;
		cout<<"Rate: "<<rate<<endl;
		cout<<"CommissionSalary: "<<salary<<endl;
	}
};

// Derived class from SalariedEmployee and CommissionEmployee with multiple inheritance
class SalariedCommissionEmployee : public SalariedEmployee, public CommissionEmployee {
public:

	// Data member to store the salary
	float salary;

	// Default constructor
	SalariedCommissionEmployee() : SalariedEmployee(), CommissionEmployee() {
		salary = 0;
	}

	// Parameterized constructor
	SalariedCommissionEmployee(float salary) : SalariedEmployee(), CommissionEmployee() {
		this->salary = salary;
	}

	// Method to calculate the salary
	void calculateSalary() {
		salary = SalariedEmployee::salary + CommissionEmployee::salary;
	}

	// Method to display the salary
	void display() {
		cout<<"Weekly+Commission salary: "<<salary;
	}

};


// Definition of our main() function
int main() {
	// Prompting the user with a menu
	int ch;
	cout<<"1. Salaried Employee"<<endl;
	cout<<"2. Hourly Employee"<<endl;
	cout<<"3. Commission Employee"<<endl;
	cout<<"4. Salaried Commission Employee"<<endl;
	cout<<"Enter choice: ";
	// Accepting choice and passing into switch-case structure
	cin>>ch;
	// Ignore the newline because of pressing enter key so that we can enter name
	cin.ignore(1, '\n');
	switch (ch) {
		case 1: {
			// Case for salaried employees, create object and call method accordingly
			cout<<"SALARIED EMPLOYEE"<<endl;
			SalariedEmployee* s = new SalariedEmployee();
			s->Employee::accept();
			s->accept();
			s->Employee::display();
			s->calculateSalary();
			s->display();
			delete s;
			break;
		}
		case 2: {
			// Case for hourly employees, create object and call method accordingly
			cout<<"HOURLY EMPLOYEE"<<endl;
			HourlyEmployee* h = new HourlyEmployee();
			h->Employee::accept();
			h->accept();
			h->Employee::display();
			h->calculateSalary();
			h->display();
			delete h;
			break;
		}
		case 3: {
			// Case for commission employee, create object and call method accordingly
			cout<<"COMMISSION EMPLOYEE"<<endl;
			CommissionEmployee* c = new CommissionEmployee();
			c->Employee::accept();
			c->accept();
			c->Employee::display();
			c->calculateSalary();
			c->display();
			delete c;
			break;
		}
		case 4: {
			// Case for salaried commission employee, create object and call method accordingly
			cout<<"SALARIED COMMISSION EMPLOYEE"<<endl;
			SalariedCommissionEmployee* sc = new SalariedCommissionEmployee();
			sc->Employee::accept();
			sc->SalariedEmployee::accept();
			sc->CommissionEmployee::accept();
			sc->Employee::display();
			sc->SalariedEmployee::calculateSalary();
			sc->SalariedEmployee::display();
			sc->CommissionEmployee::calculateSalary();
			sc->CommissionEmployee::display();
			sc->calculateSalary();
			sc->display();
			delete sc;
			break;
		}
		default: {
			// Default case, when the input matches none of the choices
			cerr<<"Invalid input!"<<endl;
		}
	}
	return 0;
}

/*
OUTPUT :-
1. Salaried Employee
2. Hourly Employee
3. Commission Employee
4. Salaried Commission Employee
Enter choice: 4
SALARIED COMMISSION EMPLOYEE
Enter employee name: employee name
Enter employee id: 1
Enter weekly salary: 25000
Enter sales: 250000
Enter rate: 10
Name: employee name
Employee ID: 1
Salary: 25000
Sales: 250000
Rate: 10
CommissionSalary: 25000
Weekly+Commission salary: 50000
*/
