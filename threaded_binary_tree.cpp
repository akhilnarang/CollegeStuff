#include <iostream>

#define MAX 20

using namespace std;

class node {
   public:
    char data[MAX];
    node* left;
    node* right;
    int lbit;
    int rbit;

    node() {
        left = right = NULL;
        lbit = rbit = 1;
    }
};

class tree {
    node* head;

   public:
    tree() {
        head = new node;
        head->rbit = 0;
        head->left = head->right = head;
    }

    void create() {
        node* root = new node;
        node* temp;
        node* current;
        cout << "Enter data for root!" << endl;
        cout << "data: ";
        cin >> root->data;
        head->left = root;
        root->left = root->right = head;
        int flag;
        char ch;
        int count;
        do {
            count = 1;
            current = root;
            flag = 0;
            temp = new node;
            cout << "Enter data for node!" << endl;
            cout << "data: ";
            cin >> temp->data;
            while (!flag) {
                cout << "Level: " << count << endl;
                do {
                    cout << "Do you want to enter on the left or the right? "
                            "Enter l/r!"
                         << endl;
                    cout << "ch: ";
                    cin >> ch;
                } while (ch != 'l' && ch != 'r');
                if (ch == 'l') {
                    if (current->lbit) {
                        temp->left = current->left;
                        temp->right = current;
                        current->lbit = 0;
                        current->left = temp;
                        flag = 1;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->rbit) {
                        temp->left = current;
                        temp->right = current->right;
                        current->rbit = 0;
                        current->right = temp;
                        flag = 1;
                    } else {
                        current = current->right;
                    }
                }
                count++;
            }
            cout << "Do you want to continue? If so, enter y" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch == 'y');
    }

    void inorder() {
        node* current = head->left;
        while (!current->lbit) {
            current = current->left;
        }
        while (current != head) {
            cout << current->data << endl;
            current = current->right;
        }
    }

    void inorder_successor(node* current) {
        if (current->right == head) return;
        cout << current->right->data << endl;
    }
};

int main() {
    tree t;
    t.create();
    t.inorder();
}