//============================================================================
// Name        : TelephoneDirectory.cpp
// Author      : Akhil Narang
// Version     :
// Copyright   :
// Description : TelephoneDirectory in C++, Ansi-style
//============================================================================

#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream i;
    ofstream o;
    bool found = false;
    o.open("/home/student/data.txt");
    int num = 0;
    while (num++ < 5) {
        cout << "Enter name and phone number on one line!\n";
        string details;
        getline(cin, details);
        o << details << "\n";
    }
    o.close();
    i.open("/home/student/data.txt");
    cout << "Enter a name to search: ";
    string name;
    getline(cin, name);
    while (!i.eof()) {
        string n, l;
        getline(i, l);
        n = l.substr(0, l.find(' '));
        if (!n.compare(name)) {
            cout << "Found details:\n" << l << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << name << " details not found in directory!";
    }
    i.close();
    return 0;
}
