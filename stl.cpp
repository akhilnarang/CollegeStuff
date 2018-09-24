//============================================================================
// Name    	: stl.cpp
// Author  	: Akhil Narang
// Version 	:
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

class Item {
    static list<Item> l;
    static list<Item>::iterator itr;

    int code;
    string name;
    double cost;
    int quantity;

   public:
    void accept(bool front) {
        cout << "Enter details!" << endl;
        cout << "Code: ";
        cin >> code;
        cout << "Name: ";
        cin >> name;
        cout << "Cost: ";
        cin >> cost;
        cout << "Quantity: ";
        cin >> quantity;
        if (front) {
            l.push_front(*this);
        } else {
            l.push_back(*this);
        }
    }

    void display() {
        cout << "Code: " << code << "\n";
        cout << "Name: " << name << "\n";
        cout << "Cost: " << cost << "\n";
        cout << "Quantity: " << quantity << "\n";
    }

    void show_container() {
        for (itr = l.begin(); itr != l.end(); itr++) {
            itr->display();
        }
    }

    void remove_item_end() {
        itr = l.end();
        itr--;
        itr = l.erase(itr);
        cout << "Last item has been removed!\n";
    }

    void remove_item_start() {
        itr = l.begin();
        itr = l.erase(itr);
        cout << "First item has been removed!\n";
    }

    void sort() {
        cout << "Sorting items!\n";
        l.sort();
    }

    void search() {
        cout << "code: ";
        int code;
        cin >> code;
        this->code = code;
        itr = find(l.begin(), l.end(), *this);
        if (itr != l.end()) {
            cout << "Item with code " << code << " exists!\n";
            itr->display();
        } else {
            cout << "Item with code " << code << " does not exist!\n";
        }
    }

    bool operator==(const Item& i) { return this->code == i.code; }
    bool operator<(const Item& i) { return this->code < i.code; }

    Item(int code) { this->code = code; }

    Item() {}
};

list<Item> Item::l;
list<Item>::iterator Item::itr;

int main() {
    int ch;
    Item I;
    do {
        cout << "1 accept front, 2 accept back, 3 remove front, 4 remove back, "
                "5 sort, 6 search, 7 to display, and 0 exit!\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                I.accept(true);
                I.show_container();
                break;

            case 2:
                I.accept(false);
                I.show_container();
                break;
            case 3:
                I.remove_item_start();
                I.show_container();
                break;
            case 4:
                I.remove_item_end();
                I.show_container();
                break;
            case 5:
                I.sort();
                cout << "Sorted list is: \n";
                I.show_container();
                break;
            case 6:
                I.search();
                break;
            case 7:
                I.show_container();
                break;
            default:
                cout << "Invalid input! Please read the options carefully!";
        }
    } while (ch != 0);
    return 0;
}
