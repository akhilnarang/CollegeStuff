#include <iostream>

#define MAX 10

using namespace std;

class node {
   public:
    char data[MAX];
    node* left;
    node* right;

    node() { left = right = NULL; }
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

    void inorder() { inorder(root); }

    void inorder(node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }

    void preorder() { preorder(root); }

    void preorder(node* root) {
        if (root == NULL) return;
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }

    void postorder() { postorder(root); }

    void postorder(node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }
};

int main() {
    tree t;
    t.create();
    cout << "Inorder!" << endl;
    t.inorder();
    cout << "Preorder!" << endl;
    t.preorder();
    cout << "Postorder!" << endl;
    t.postorder();
}
