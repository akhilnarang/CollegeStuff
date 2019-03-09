#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class term {
    int coeff, exp;
    term* next;
    friend class poly;
};

class poly {
    term* head;

   public:
    poly() {
        head = new term;
        head->exp = -1;
        head->next = head;
    }

    void create_poly();
    void display_poly();
    void add_poly(poly, poly);
    int eval_poly();
};

void poly::create_poly() {
    term *temp, *current = head;
    int i, n;
    cout << "Enter number of terms!" << endl;
    cout << "n: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        temp = new term;
        cout << "Enter values!" << endl;
        cout << "exp: ";
        cin >> temp->exp;
        cout << "coeff: ";
        cin >> temp->coeff;
        temp->next = head;
        current->next = temp;
        current = temp;
    }
}

void poly::display_poly() {
    if (head->next == head) {
        cout << "No terms!" << endl;
        return;
    }
    int first = 1;
    term* temp = head->next;
    while (temp != head) {
        if (temp->coeff >= 0) {
            if (!first) {
                cout << "+ ";
            } else {
                first = 0;
            }
        }
        cout << temp->coeff;
        if (temp->exp != 0) {
            cout << "x^" << temp->exp;
        }
        cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

void poly::add_poly(poly p1, poly p2) {
    term* temp1 = p1.head->next;
    term* temp2 = p2.head->next;
    term* temp3 = head;
    term* temp = new term;
    term* current = temp3;
    while (temp1->exp == -1 && temp2->exp == -1) {
        if (temp1->exp == temp2->exp) {
            temp->coeff = temp1->coeff + temp2->coeff;
            temp->exp = temp1->exp;
            temp->next = temp3;
            current->next = temp;
            current = temp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            temp->coeff = temp1->coeff;
            temp->exp = temp1->exp;
            temp->next = temp3;
            current->next = temp;
            current = temp;
            temp1 = temp1->next;
        } else {
            temp->coeff = temp2->coeff;
            temp->exp = temp2->exp;
            temp->next = temp3;
            current->next = temp;
            current = temp;
            temp2 = temp2->next;
        }
    }
    while (temp1->exp != -1) {
        temp = new term;
        temp->coeff = temp1->coeff;
        temp->exp = temp1->exp;
        temp->next = temp3;
        current->next = temp;
        current = temp;
        temp1 = temp1->next;
    }
    while (temp2->exp != -1) {
        temp = new term;
        temp->coeff = temp2->coeff;
        temp->exp = temp2->exp;
        temp->next = temp3;
        current->next = temp;
        current = temp;
        temp2 = temp2->next;
    }
}

int poly::eval_poly() {
    int x, answer = 0;
    cout << "Enter value of x!" << endl;
    cout << "x: ";
    cin >> x;
    term* temp = head;
    if (temp->next == temp) {
        cout << "No terms!" << endl;
        exit(1);
    }
    temp = head->next;
    while (temp != head) {
        answer += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return answer;
}

int main() {
    poly p1, p2, p3;
    int ch;
    do {
        cout << "Enter 1 for creating polynomial, 2 for displaying, ";
        cout << "3 for adding, 4 for evaluating result!" << endl;
        cout << "ch: ";
        cin >> ch;
        switch (ch) {
            case 1:
                p1.create_poly();
                break;
            case 2:
                p1.display_poly();
                break;
            case 3:
                p1.create_poly();
                p2.create_poly();
                p3.add_poly(p1, p2);
                p3.display_poly();
                break;
            case 4:
                cout << "Answer is " << p1.eval_poly() << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
        cout << "Enter 0 to exit!" << endl;
        cout << "ch: ";
        cin >> ch;
    } while (ch != 0);
    return 0;
}
