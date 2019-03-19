#include <string.h>
#include <iostream>

#define MAX 20

using namespace std;

class node {
   public:
    char word[MAX];
    char meaning[MAX];
    node *left, *right;

    node() { left = right = NULL; }
};

class queue {
    node* data[MAX];
    int front, rear;

   public:
    queue() { front = rear = 0; }

    int isEmpty() { return front == rear; }

    int isFull() { return rear == MAX - 1; }

    void enqueue(node* data) {
        if (isFull()) return;
        this->data[++rear] = data;
    }

    node* dequeue() {
        if (isEmpty()) return new node;
        node* temp = data[front++];
        cout << temp->data << endl;
        return temp;
    }

    node* getFront() { return data[front]; }
};

class dictionary {
    node* root;

   public:
    dictionary() { root = NULL; }

    void create() {
        root = new node;
        cout << "Enter word and meaning!" << endl;
        cout << "word: ";
        cin >> root->word;
        cout << "meaning: ";
        cin >> root->meaning;
        create(root);
    }

    void create(node* root) {
        node *temp, *current;
        bool flag;
        char ch;
        int count;
        do {
            count = 1;
            temp = root;
            flag = true;
            current = new node;
            cout << "Enter word and meaning!" << endl;
            cout << "word: ";
            cin >> current->word;
            cout << "meaning: ";
            cin >> current->meaning;
            while (flag) {
                cout << "Level: " << count << endl;
                if (strcmp(temp->word, current->word) > 0) {
                    if (temp->left == NULL) {
                        temp->left = current;
                        flag = false;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = current;
                        flag = false;
                    } else {
                        temp = temp->right;
                    }
                }
                count++;
            }
            cout << "Do you want to continue? If so, enter y" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch == 'y');
        cout << root->word << " - " << root->meaning << endl;
        cout << root->left->word << " - " << root->left->meaning << endl;
        cout << root->right->word << " - " << root->right->meaning << endl;
    }

    void remove() { cout << "Enter word to be removed!" << endl; }

    void inorder() { inorder(root); }

    void inorder(node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->word << " - " << root->meaning << endl;
        inorder(root->right);
    }

    void bft() {}

    void mirrorImageRecursive() {}

    void mirrorImageIterative() {}
};

int main() {
    int ch;
    dictionary d;
    do {
        cout << "Enter 1 to insert!" << endl;
        cout << "Enter 2 to delete!" << endl;
        cout << "Enter 3 to traverse inorder!" << endl;
        cout << "Enter 4 for BFT!" << endl;
        cout << "Enter 5 for recursive mirror image!" << endl;
        cout << "Enter 6 for iterative mirror image!" << endl;
        cout << "Enter 7 for recursive copy!" << endl;
        cout << "Enter 0 to exit!" << endl;
        cout << "ch: ";
        cin >> ch;

        switch (ch) {
            case 1:
                d.create();
                break;
            case 2:
                d.remove();
                break;
            case 3:
                d.inorder();
                break;
        }
    } while (ch != 0);
    return 0;
}
