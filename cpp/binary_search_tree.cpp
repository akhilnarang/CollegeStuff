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
        this->data[rear++] = data;
    }

    node* dequeue() {
        if (isEmpty()) return new node;
        node* temp = data[front++];
        cout << temp->word << " - " << temp->meaning << endl;
        return temp;
    }

    node* getFront() { return data[front]; }
};

class dictionary {
    node* root;

   public:
    dictionary() { root = NULL; }

    void create() {
        node* current;
        char ch;
        root = new node;
        cout << "Enter root word and meaning!" << endl;
        cout << "word: ";
        cin >> root->word;
        cout << "meaning: ";
        cin >> root->meaning;
        do {
            current = new node;
            cout << "Enter word and meaning!" << endl;
            cout << "word: ";
            cin >> current->word;
            cout << "meaning: ";
            cin >> current->meaning;
            insert(root, current);
            cout << "Do you want to continue? If so, enter y" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch == 'y');
    }

    void insert(node* root, node* data) {
        if (strcmp(root->word, data->word) > 0) {
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

    void remove() {
        char word[MAX];
        node* current = root;
        node* parent = root;
        cout << "Enter word to be removed!" << endl;
        cout << "word: ";
        cin >> word;
        if (!strcmp(current->word, word)) {
            node* temp = current->left;
            current = current->right;
            cout << "Deleting root node " << root->word << " - "
                 << root->meaning << endl;
            root = current;
            while (current->left != NULL) {
                current = current->left;
            }
            current->left = temp;
        } else {
            while (current != NULL) {
                if (strcmp(current->word, word) > 0) {
                    parent = current;
                    current = current->left;
                } else if (strcmp(current->word, word) < 0) {
                    parent = current;
                    current = current->right;
                } else {
                    if (current->left == NULL && current->right == NULL) {
                        cout << "Deleting leaf node" << current->word << " - "
                             << current->meaning << endl;
                        delete current;
                    } else if (current->left == NULL &&
                               current->right != NULL) {
                        cout << "Deleting node with 1 child -> "
                             << current->word << " - " << current->meaning
                             << endl;
                        node* temp = current->right;
                        current = parent;
                        current->right = temp;
                    } else if (current->left != NULL &&
                               current->right == NULL) {
                        cout << "Deleting node with 1 child -> "
                             << current->word << " - " << current->meaning
                             << endl;
                        node* temp = current->left;
                        current = parent;
                        current->left = temp;
                    } else if (current->left != NULL &&
                               current->right != NULL) {
                        cout << "Deleting node with 2 children -> "
                             << current->word << " - " << current->meaning
                             << endl;
                        node* temp = current->left;
                        node* right = current->right;
                        current = parent;
                        current->right = right;
                        while (current->left != NULL) {
                            current = current->left;
                        }
                        current->left = temp;
                    }
                    break;
                }
            }
        }
    }

    void inorder() { inorder(root); }

    void inorder(node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->word << " - " << root->meaning << endl;
        inorder(root->right);
    }

    void bft() { bft(root); }

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

    void mirrorRecursive() {
        mirrorRecursive(root);
        bft(root);
    }

    void mirrorRecursive(node* root) {
        if (root == NULL) return;
        mirrorRecursive(root->left);
        mirrorRecursive(root->right);
        node* t = root->left;
        root->left = root->right;
        root->right = t;
    }

    void mirrorIterative() {
        queue q;
        node* temp = root;
        q.enqueue(root);
        while (!q.isEmpty()) {
            temp = q.dequeue();
            node* t = temp->left;
            temp->left = temp->right;
            temp->right = t;
            if (temp->left) q.enqueue(temp->left);
            if (temp->right) q.enqueue(temp->right);
        }
    }

    void copy(dictionary* d) { this->root = copy(d->root); }

    node* copy(node* root) {
        if (root == NULL) {
            return root;
        }
        node* temp = root;
        temp->left = copy(root->left);
        temp->right = copy(root->right);
        return temp;
    }

    void search() {
        char word[MAX];
        cout << "Enter word to search for!" << endl;
        cout << "word: ";
        cin >> word;
        search(word, root);
    }

    void search(char word[], node* root) {
        if (root == NULL) {
            cout << "Word \'" << word << "\' not found in dictionary!" << endl;
            return;
        }
        if (strcmp(root->word, word) > 0) {
            search(word, root->left);
        } else if (strcmp(root->word, word) < 0) {
            search(word, root->right);
        } else {
            cout << "Word found in dictionary!" << endl;
            cout << root->word << " - " << root->meaning << endl;
            return;
        }
    }
};

int main() {
    int ch;
    dictionary d;
    dictionary temp;
    do {
        cout << "Enter 1 to insert!" << endl;
        cout << "Enter 2 to delete!" << endl;
        cout << "Enter 3 to traverse inorder!" << endl;
        cout << "Enter 4 for BFT!" << endl;
        cout << "Enter 5 for recursive mirror!" << endl;
        cout << "Enter 6 for iterative mirror!" << endl;
        cout << "Enter 7 for recursive copy!" << endl;
        cout << "Enter 8 for search!" << endl;
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
            case 4:
                d.bft();
                break;
            case 5:
                d.mirrorRecursive();
                break;
            case 6:
                d.mirrorIterative();
                break;
            case 7:
                temp.copy(&d);
                temp.bft();
                break;
            case 8:
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