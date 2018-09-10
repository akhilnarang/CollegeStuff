#include <iostream>
#include <string>

using namespace std;

class Student {
    string name;
    int rollNo;

  public:
    Student() {
        name = "";
        rollNo = 0;
    }

    ~Student() { cout << "Destroying " << this << endl; }

    void accept() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll number: " << rollNo << endl;
    }
};

int main() {
    Student s;
    s.accept();
    s.display();
    return 0;
}