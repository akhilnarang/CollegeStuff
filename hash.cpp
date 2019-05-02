#include <iostream>
#include <string>

#define MAX 10

using namespace std;

class student {
    friend class Hash;
    int rollNumber;
    string name;
    char grade;

    student() {
        rollNumber = -1;
        name = "";
        grade = '\0';
    }
};

class Hash {
    student hash_table[MAX];

    void display() {
        cout << "Serial Number\tRoll Number\tName\tGrade" << endl;
        for (int i = 0; i < MAX; i++) {
            if (hash_table[i].rollNumber == -1) {
                cout << i << "\t\t\t\t\t" << hash_table[i].name << "\t"
                     << hash_table[i].grade << endl;
            } else {
                cout << i << "\t\t" << hash_table[i].rollNumber << "\t\t"
                     << hash_table[i].name << "\t" << hash_table[i].grade
                     << endl;
            }
        }
    }

   public:
    void linear_probing_noreplace() {
        student s;
        int ch, flag, index, location;
        do {
            ch = flag = 0;
            cout << "Enter student details!" << endl;
            cout << "Roll Number: ";
            cin >> s.rollNumber;
            cout << "Name: ";
            cin >> s.name;
            cout << "Grade: ";
            cin >> s.grade;

            location = index = s.rollNumber % MAX;

            while (!flag && hash_table[index].rollNumber != -1) {
                index = ++index % MAX;
                ch = 1;
                flag = index == location;
            }

            if (flag && ch) {
                cout << "No space left in hashtable" << endl;
            } else {
                hash_table[index] = s;
            }
            display();
            cout << "Enter 0 to exit!" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch);
    }

    void linear_probing_replace() {
        student s, temp;
        int ch, flag, index, location;
        do {
            ch = flag = 0;
            cout << "Enter student details!" << endl;
            cout << "Roll Number: ";
            cin >> s.rollNumber;
            cout << "Name: ";
            cin >> s.name;
            cout << "Grade: ";
            cin >> s.grade;

            location = index = s.rollNumber % MAX;

            if (hash_table[index].rollNumber != -1) {
                if (hash_table[index].rollNumber % MAX != index) {
                    temp = hash_table[index];
                    hash_table[index] = s;
                    s = temp;
                }
            }

            while (!flag && hash_table[index].rollNumber != -1) {
                index = ++index % MAX;
                ch = 1;
                flag = index == location;
            }

            if (flag && ch) {
                cout << "No space left in hashtable" << endl;
            } else {
                hash_table[index] = s;
            }

            display();
            cout << "Enter 0 to exit!" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch);
    }
};

int main() {
    Hash hash;
    int ch;
    cout << "Enter 1 for linear probing without replacement!" << endl;
    cout << "Enter 2 for linear probing with replacement!" << endl;
    cout << "Enter 0 to exit!" << endl;
    cout << "Enter your choice!" << endl;
    cout << "ch: ";
    cin >> ch;
    do {
        switch (ch) {
            case 1:
                hash.linear_probing_noreplace();
                break;
            case 2:
                hash.linear_probing_replace();
                break;
            case 0:
                exit(1);
            default:
                cout << "Wrong choice, please read the options again!" << endl;
        }
        cout << "Enter 0 to exit, any of the other options to continue!"
             << endl;
        cout << "ch: " << endl;
        cin >> ch;
    } while (ch);
}
