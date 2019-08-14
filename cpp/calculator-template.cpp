#include <iostream>

using namespace std;

template <typename T>
class Calculator {
    T a, b;

   public:
    Calculator() { a = b = 0; }

    void accept() {
        cout << "Enter values!" << endl;
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
    }

    void calculate() {
        cout << "Choose operation + - * or /\n";
        cout << "ch: ";
        char ch;
        cin >> ch;
        switch (ch) {
            case '+':
                cout << "The sum of a and b is " << a + b << "!\n";
                break;
            case '-':
                cout << "The difference between a and b is " << a - b << "!\n";
                break;
            case '*':
                cout << "The product of a and b is " << a * b << "!\n";
                break;
            case '/':
                cout << "The quotient of a and b is " << a / b << "!\n";
                break;
            default:
                cout << "Invalid input!\n";
        }
    }
};

template <typename T>
void stuff(Calculator<T> calculator) {
    calculator.accept();
    calculator.calculate();
}

int main() {
    cout << "Enter 1 for Integer, and 2 for Double type "
            "data!\n";
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    switch (ch) {
        case 1: {
            Calculator<int> calculator;
            stuff(calculator);
            break;
        }
        case 2: {
            Calculator<double> greatest;
            stuff(greatest);
            break;
        }
        default:
            cout << "Wrong choice!\n";
    }
    return 0;
}