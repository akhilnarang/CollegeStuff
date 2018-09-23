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
  int code;
  string name;
  double cost;
  int quantity;

public:
  void accept();
  void display();
  void show_container();
  void remove_item_end();
  void remove_item_start();
  void sort();
  void search();
  bool operator==(const Item &i) { return i.code == this->code; }
  bool operator<(const Item &i) { return i.code < this->code; }
  Item(int code) { this->code = code; }

  Item() {}
};

Item I;
list<Item> l;
list<Item>::iterator itr;

void Item::accept() {
  cout << "Enter details!" << endl;
  cout << "Code: ";
  cin >> code;
  cout << "Name: ";
  cin >> name;
  cout << "Cost: ";
  cin >> cost;
  cout << "Quantity: ";
  cin >> quantity;
}

void Item::display() {
  cout << "Code: " << code << "\n";
  cout << "Name: " << name << "\n";
  cout << "Cost: " << cost << "\n";
  cout << "Quantity: " << quantity << "\n";
}

void Item::show_container() {
  for (itr = l.begin(); itr != l.end(); itr++) {
    itr->display();
  }
}

void Item::remove_item_end() {
  itr = l.end();
  itr--;
  itr = l.erase(itr);
  cout << "Last item has been removed!\n";
}

void Item::remove_item_start() {
  itr = l.begin();
  itr = l.erase(itr);
  cout << "First item has been removed!\n";
}

void Item::sort() {
  cout << "Sorting items!\n";
  l.sort();
}

void Item::search() {
  cout << "code: ";
  int code;
  cin >> code;
  I.code = code;
  itr = find(l.begin(), l.end(), I);
  if (itr != l.end()) {
    cout << "Item with code " << code << " exists!\n";
    itr->display();
  } else {
    cout << "Item with code " << code << " does not exist!\n";
  }
}

int main() {
  int ch;
  do {
    cout << "1 accept front, 2 accept back, 3 remove front, 4 remove back, "
            "5 sort, 6 search, 0 exit!\n";
    cout << "Enter choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      I.accept();
      l.push_front(I);
      I.show_container();
      break;

    case 2:
      I.accept();
      l.push_back(I);
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
    default:
      cout << "Invalid input! Please read the options carefully!";
    }
  } while (ch != 0);
  return 0;
}
