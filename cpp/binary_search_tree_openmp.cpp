#include <omp.h>
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
#pragma omp parallel for
        for (int i = 0; i < 4; i++) {
            queue q;
            node* temp = root;
            q.enqueue(root);
            while (!q.isEmpty()) {
                temp = q.dequeue();
                if (temp->value == i) {
                    printf("Found value %d on thread %d\n", i,
                           omp_get_thread_num());
                }
                if (temp->left) q.enqueue(temp->left);
                if (temp->right) q.enqueue(temp->right);
            }
        }
    }
};

int main() {
    int ch;
    tree d;
    d.create();
    d.bft();
    return 0;
}