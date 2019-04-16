#include <string.h>
#include <iostream>

#define MAX 20

using namespace std;
class node {
   public:
    int vertex;
    char name[MAX];
    node* next;
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
        cout << temp->name << endl;
        return temp;
    }

    node* getTop() { return data[top]; }
};

class graph {
    node* head[MAX];
    int n, visited[MAX];

   public:
    graph() {
        int i;
        cout << "Enter number of people in the network!\n";
        cout << "n: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            head[i] = new node;
            cout << "Enter name of user " << i + 1 << "!\n";
            cout << "name: ";
            cin >> head[i]->name;
            head[i]->vertex = i;
        }
    }

    int index(char* name) {
        int i;
        for (i = 0; i < n; i++) {
            if (!strcmp(head[i]->name, name)) return i;
        }
        cout << "name " << name << " not found!\n";
        return -1;
    }

    void reset() {
        int i;
        for (i = 0; i < n; i++) {
            visited[i] = 0;
        }
    }

    void create() {
        node *temp, *current;
        int v;
        char ch;
        for (int i = 0; i < n; i++) {
            temp = head[i];
            cout << "vertex: " << head[i]->name << endl;
            do {
                current = new node;
                do {
                    cout << "Enter adjacent vertex!\n";
                    cout << "v: ";
                    cin >> v;
                } while (v == i);
                current->vertex = v;
                strcpy(current->name, head[v]->name);
                temp->next = current;
                temp = temp->next;
                cout << "Enter y to continue!\n";
                cout << "ch: ";
                cin >> ch;
            } while (ch == 'y');
        }
    }

    void display() {
        node* temp;
        for (int i = 0; i < n; i++) {
            temp = head[i]->next;
            cout << head[i]->name;
            while (temp) {
                cout << " ->  " << temp->name;
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    void dfs() {
        node* temp;
        int i, k;
        char name[MAX];
        cout << "Enter name!\n";
        cout << "name: ";
        cin >> name;
        reset();
        k = index(name);
        if (k == -1) {
            return;
        }
        temp = head[k];
        dfs(temp);
    }

    void dfs(node* temp) {
        int k = index(temp->name);
        if (k == -1) {
            return;
        }
        cout << temp->name << endl;
        visited[k] = 1;
        while (temp) {
            int k = index(temp->name);
            if (k == -1) {
                return;
            }
            if (!visited[k]) {
                dfs(temp);
            }
            if (temp->next != NULL) {
                if (!visited[temp->next->vertex])
                    temp = head[temp->next->vertex];
            }
        }
    }

    void dfs_iterative() {
        int v;
        reset();
        cout << "Enter vertex!" << endl;
        cout << "v: ";
        cin >> v;
    }
};

int main() {
    graph g;
    g.create();
    g.display();
    g.dfs();
}