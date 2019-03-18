#include <iostream>

#define MAX 20

using namespace std;

class node {
   public:
    char data[MAX];
    node* left;
    node* right;

    node() { left = right = NULL; }
};

class stack {
    node* data[MAX];
    int top;

   public:
    stack() { top = -1; }

    int isEmpty() { return top == -1; }

    int isFull() { return top == MAX - 1; }

    void push(node* data) {
        if (isFull()) return;
        this->data[++top] = data;
    }

    node* pop() {
        if (isEmpty()) return new node;
        node* temp = data[top--];
        cout << temp->data << endl;
        return temp;
    }

    node* getTop() { return data[top]; }
};

class tree {
    node* root;

   public:
    tree() { root = NULL; }

    void create() {
        root = new node;
        cout << "Enter data for node!" << endl;
        cout << "data: ";
        cin >> root->data;
        create(root);
    }

    void create(node* root) {
        char ch;
        node* temp;
        cout << "root->data = " << root->data << endl;
        cout << "Do you want to enter data to the left? Enter y" << endl;
        cout << "ch: ";
        cin >> ch;
        if (ch == 'y') {
            temp = new node;
            cout << "Enter data for node!" << endl;
            cout << "data: ";
            cin >> temp->data;
            root->left = temp;
            create(temp);
        }
        cout << "root->data = " << root->data << endl;
        cout << "Do you want to enter data to the right? Enter y" << endl;
        cout << "ch: ";
        cin >> ch;
        if (ch == 'y') {
            temp = new node;
            cout << "Enter data for node!" << endl;
            cout << "data: ";
            cin >> temp->data;
            root->right = temp;
            create(temp);
        }
    }

    void create_iterative() {
        root = new node;
        cout << "Enter data for root!" << endl;
        cout << "data: ";
        cin >> root->data;
        create_iterative(root);
    }

    void create_iterative(node* root) {
        node *temp, *current;
        int flag;
        char ch;
        int count;
        do {
            count = 1;
            temp = root;
            flag = 0;
            current = new node;
            cout << "Enter data for node!" << endl;
            cout << "data: ";
            cin >> current->data;
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
                    if (temp->left == NULL) {
                        temp->left = current;
                        flag = 1;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = current;
                        flag = 1;
                    }
                    temp = temp->right;
                }
                count++;
            }
            cout << "Do you want to continue? If so, enter y" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch == 'y');
    }

    void inorder() { inorder(root); }

    void inorder(node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }

    void inorder_iterative() {
        node* temp = root;
        stack s;
        while (1) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            if (s.isEmpty()) break;
            temp = s.pop()->right;
        }
    }

    void preorder() { preorder(root); }

    void preorder(node* root) {
        if (root == NULL) return;
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }

    void preorder_iterative() {
        node* temp = root;
        stack s;
        s.push(temp);
        while (!s.isEmpty()) {
            temp = s.pop();
            if (temp->right != NULL) s.push(temp->right);
            if (temp->left != NULL) s.push(temp->left);
        }
    }

    void postorder() { postorder(root); }

    void postorder(node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }

    void postorder_iterative() {
        node* temp = root;
        stack s;
        while (1) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            if (s.isEmpty()) break;
            if (s.getTop()->right == NULL) {
                temp = s.pop();
            }
            while (!s.isEmpty() && s.getTop()->right == temp) {
                temp = s.pop();
            }
            temp = s.getTop()->right;
        }
    }
};

int main() {
    tree t;
    int ch;
    do {
        cout << "1. Create Recursively" << endl;
        cout << "2. Create Iteratively" << endl;
        cout << "3. Display inorder recursively" << endl;
        cout << "4. Display inorder iteratively" << endl;
        cout << "5. Display preorder recursively" << endl;
        cout << "6. Display preorder iteratively" << endl;
        cout << "7. Display postorder recursively" << endl;
        cout << "8. Display postorder iteratively" << endl;
        cout << "9. To erase the tree" << endl;
        cout << "0. To exit" << endl;
        cout << "ch: ";
        cin >> ch;
        switch (ch) {
            case 1:
                t.create();
                break;
            case 2:
                t.create_iterative();
                break;
            case 3:
                t.inorder();
                break;
            case 4:
                t.inorder_iterative();
                break;
            case 5:
                t.preorder();
                break;
            case 6:
                t.preorder_iterative();
                break;
            case 7:
                t.postorder();
                break;
            case 8:
                t.postorder_iterative();
                break;
            case 9:
                t.erase();
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while (ch != 0);
}
