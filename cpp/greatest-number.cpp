#include <iostream>

using namespace std;

template <typename T>
class Greatest {
    T a, b;

   public:
    Greatest() { a = b = 0; }

    void accept() {
        cout << "Enter values!" << endl;
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
    }

    void check() {
        if (a > b) {
            cout << "a > b" << endl;
        } else if (b > a) {
            cout << "b > a" << endl;
        } else {
            cout << "a = b" << endl;
        }
    }
};

template <typename T>
void stuff(Greatest<T> greatest) {
    greatest.accept();
    greatest.check();
}

int main() {
    cout << "Enter 1 for Integer, and 2 for Double type "
            "data!\n";
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    switch (ch) {
        case 1: {
            Greatest<int> greatest;
            stuff(greatest);
            break;
        }
        case 2: {
            Greatest<double> greatest;
            stuff(greatest);
            break;
        }
        default:
            cout << "Wrong choice!\n";
    }
    return 0;
}