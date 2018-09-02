#include <iostream>
#include <string>

using namespace std;

class Bank {
    string name;
    int accountNumber;
    float balance;

public:

    Bank() {
        name = "";
        accountNumber = 0;
        balance = 0.0;
    }
    Bank(string name, int accountNumber, float balance) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void accept() {
        cout<<"Enter name: ";
        getline(cin, name);
        cout<<"Enter account number: ";
        cin>>accountNumber;
        cout<<"Enter balance: ";
        cin>>balance;
    }

    void deposit(float amount) {
        cout<<"Current balance: "<<balance<<endl;
        cout<<"Trying to deposit: "<<amount<<endl;
        balance += amount;
        cout<<"New balance: "<<balance<<endl;
    }

    void withdraw(float amount) {
        cout<<"Current balance: "<<balance<<endl;
        cout<<"Trying to withdraw: "<<amount<<endl;
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout<<"Not enough balance to withdraw "<<amount<<endl;
            return;
        }
        cout<<"New balance: "<<balance<<endl;
    }

    void display() {
        cout<<"Name: "<<name<<endl;
        cout<<"Account number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

int main() {
    Bank b;
    b.accept();
    b.display();
    b.deposit(20000);
    b.display();
    b.withdraw(1000);
    b.display();
    b.withdraw(100000);
    b.display();
}