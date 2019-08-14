/*
 * file.cpp
 *
 *  Created on: 04-Sep-2018
 *      Author: ibm
 */

#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

const char filepath[] = "./data";

class Item {
    int item_code;
    char item_name[20];
    int quantity;
    float cost;

   public:
    void addNewItem() {
        cout << "Enter item code: ";
        cin >> item_code;
        cout << "Enter item name: ";
        cin >> item_name;
        cout << "Enter quantity : ";
        cin >> quantity;
        cout << "Enter item cost: ";
        cin >> cost;
    }

    void displayItem() {
        cout << "Item code: " << item_code << endl;
        cout << "Item name: " << item_name << endl;
        cout << "Quantity:  " << quantity << endl;
        cout << "Item cost: " << cost << endl;
    }

    void displayItemTabular() {
        cout << item_code << "\t\t";
        cout << item_name << "\t\t";
        cout << quantity << "\t\t";
        cout << cost << "\n";
    }

    bool checkItem(int item_code) { return this->item_code == item_code; }

    bool checkItem(char item_name[]) {
        int n = strcmp(this->item_name, item_name);
        return n == 0 || abs(n) == 32;
    }

    int getQuantity() { return this->quantity; }

    void setQuantity(int quantity) { this->quantity = quantity; }
};

void addItem() {
    Item i;
    i.addNewItem();
    ofstream f(filepath, ios::app | ios::binary);
    f.write((char*)&i, sizeof(i));
    f.close();
}

void displayItems() {
    cout << "Item Code\tItem Name\tQuantity\tItem Cost\n";
    ifstream f(filepath, ios::binary);
    while (f >> ws && !f.eof()) {
        Item i;
        f.read((char*)&i, sizeof(i));
        i.displayItemTabular();
    }
    f.close();
}

void searchItemCode() {
    bool found = false;
    int item_code;
    cout << "Enter item code of the item you want to search for: ";
    cin >> item_code;
    ifstream f(filepath, ios::binary);
    while (!found && (f >> ws && !f.eof())) {
        Item i;
        f.read((char*)&i, sizeof(i));
        found = i.checkItem(item_code);
        if (found) {
            cout << "Item found!\n";
            i.displayItem();
        }
    }
    if (!found) {
        cout << "Item with item code " << item_code << " not found!";
    }
    f.close();
}

void searchItemName() {
    bool found = false;
    char item_name[20];
    cout << "Enter item name of the item you want to search for: ";
    cin >> item_name;
    ifstream f(filepath, ios::binary);
    while (!found && (f >> ws && !f.eof())) {
        Item i;
        f.read((char*)&i, sizeof(i));
        found = i.checkItem(item_name);
        if (found) {
            cout << "Item found!\n";
            i.displayItem();
        }
    }
    if (!found) {
        cout << "Item with item name " << item_name << " not found!";
    }
    f.close();
}

void search() {
    cout << "1 to search by code, 2 to search by name.\n";
    cout << "Enter choice: ";
    int c;
    cin >> c;
    switch (c) {
        case 1:
            searchItemCode();
            break;
        case 2:
            searchItemName();
            break;
        default:
            cout << "Wrong choice!" << endl;
    }
}

void update() {
    int pos = -1;
    bool found = false;
    int item_code;
    cout << "Enter item code of the item you want purchase: ";
    cin >> item_code;
    ifstream f(filepath, ios::binary);
    while (!found && (f >> ws && !f.eof())) {
        Item i;
        pos = f.tellg();
        f.read((char*)&i, sizeof(i));
        found = i.checkItem(item_code);
        if (found) {
            break;
        }
    }
    if (found) {
        f.seekg(pos);
        Item i;
        f.read((char*)&i, sizeof(i));
        f.close();
        if (i.getQuantity() < 1) {
            cout << "Quantity already 0 - cannot purchase!\n";
        } else {
            i.setQuantity(i.getQuantity() - 1);
            ofstream f(filepath, ios::ate | ios::binary);
            f.seekp(pos);
            f.write((char*)&i, sizeof(i));
            f.close();
        }
    } else {
        cout << "Item with item code " << item_code << " not found!";
    }
    f.close();
}

int main() {
    int ch = 0;
    do {
        cout << "Choose from the following options!" << endl;
        cout << "1. To add a new item" << endl;
        cout << "2. To display all items" << endl;
        cout << "3. To search for an item" << endl;
        cout << "4. To update the file" << endl;
        cout << "0. To exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 0:
                cout << "Exiting!";
                exit(0);
                break;
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            default: {
                cout << "Wrong choice!" << endl;
            }
        }
    } while (ch != 0);
    return 0;
}
