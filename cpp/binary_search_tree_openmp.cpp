#include <string.h>
#include <iostream>

// Maximum elements in our tree
#define MAX 20

using namespace std;

// Class to represent a node in our tree
class node {
   public:
    int value;
    node *left, *right;

    node() { left = right = NULL; }
};

// Class to represent a queue of tree nodes
class queue {
    node* data[MAX];
    int front, rear;

   public:
    queue() { front = rear = 0; }

    int isEmpty() { return front == rear; }

    int isFull() { return rear == MAX - 1; }

    void enqueue(node* data) {
        if (isFull()) return;
        this->data[rear++] = data;
    }

    node* dequeue() {
        if (isEmpty()) return new node;
        node* temp = data[front++];
        cout << temp->value << endl;
        return temp;
    }

    node* getFront() { return data[front]; }
};

// The tree itself, it has the root node as an instance variable, and functions
// that it can perform based on that
class tree {
    node* root;

   public:
    // Constructor to initialize our root as a null node
    tree() { root = NULL; }

    // Function to create the root node and call a helper insert function to
    // insert more nodes if desired
    void create() {
        node* current;
        char ch;
        root = new node;
        cout << "Enter the value!" << endl;
        cout << "value: ";
        cin >> root->value;
        do {
            current = new node;
            cout << "Enter the value!" << endl;
            cout << "value: ";
            cin >> current->value;
            insert(root, current);
            cout << "Do you want to continue? If so, enter y" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch == 'y');
    }

    // Recursive function to insert nodes into our tree based on their value
    void insert(node* root, node* data) {
        if (root->value > data->value) {
            if (root->left != NULL) {
                insert(root->left, data);
            } else {
                root->left = data;
                return;
            }
        } else {
            if (root->right != NULL) {
                insert(root->right, data);
            } else {
                root->right = data;
                return;
            }
        }
    }

    // Breadth first traversal
    void bft() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        bft(root);
    }

    void bft(node* root) {
        queue q;
        node* temp = root;
        q.enqueue(root);
        while (!q.isEmpty()) {
            temp = q.dequeue();
            if (temp->left) q.enqueue(temp->left);
            if (temp->right) q.enqueue(temp->right);
        }
    }

    // Depth first traversal
    void dft() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        dft(root);
    }

    void dft(node* root) {
        if (root == NULL) return;
        dft(root->left);
        dft(root->right);
        cout << root->value << endl;
    }

    bool dft(node* root, int value) {
        if (root == NULL) return false;
        dft(root->left, value);
        dft(root->right, value);
        cout << "root=" << root->value << endl;
        cout << "value="<< value << endl;
        if (root->value == value) {
            return true;
        }
    }

    void search() {
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }
        int value;
        cout << "Enter value to search for!" << endl;
        cout << "value: ";
        cin >> value;
        cout << value;
        if (!dft(root, value)) {
            cout << " not";
        }
        cout << " found in tree!" << endl;
    }
};

int main() {
    int ch;
    tree d;
    tree temp;
    do {
        cout << "Enter 1 to insert!" << endl;
        cout << "Enter 2 for BFT!" << endl;
        cout << "Enter 3 for DFT!" << endl;
        cout << "Enter 4 for search!" << endl;
        cout << "Enter 0 to exit!" << endl;
        cout << "ch: ";
        cin >> ch;

        switch (ch) {
            case 1:
                d.create();
                break;
            case 2:
                d.bft();
                break;
            case 3:
                d.dft();
                break;
            case 4:
                d.search();
                break;
            case 0:
                break;
            default:
                cout << "Learn to read!" << endl;
        }
    } while (ch != 0);
    return 0;
}