#include <iostream>

#define MAX 10

using namespace std;

class student {
    int marks;
    string name;
    friend class heap;
};

class heap {
    student heap_array[MAX];
    int min_max, n;

   public:
    void create() {
        int ch, i;
        cout << "Enter total number of students!" << endl;
        cout << "n: ";
        cin >> n;
        cout << "Enter 0 for max heap, any other integer for min" << endl;
        cout << "min_max: ";
        cin >> min_max;
        for (i = 1; i <= n; i++) {
            cout << "Enter student name and marks!" << endl;
            cout << "name: ";
            cin >> heap_array[i].name;
            cout << "marks: ";
            cin >> heap_array[i].marks;
            insert(i);
        }
    }

    void display() {
        int i;
        cout << "Name\tMarks" << endl;
        for (i = 1; i <= n; i++) {
            cout << heap_array[i].name << "\t" << heap_array[i].marks << endl;
        }
    }

    void insert(int index) {
        int i = index;
        student s = heap_array[index];
        if (min_max) {
#define OPERATOR <
        } else {
#define OPERATOR >
        }
        while (i > 1 && s.marks OPERATOR heap_array[i / 2].marks) {
            heap_array[i] = heap_array[i / 2];
            i = i / 2;
        }
        heap_array[i] = s;
    }

    void extract() {
        cout << "Name: " << heap_array[1].name << endl;
        cout << "Marks: " << heap_array[1].marks << endl;
    }
};

int main() {
    heap h;
    h.create();
    h.display();
    cout << endl << "Root value: " << endl;
    h.extract();
    return 0;
}