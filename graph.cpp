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
        cout << temp->name << endl;
        return temp;
    }

    node* getFront() { return data[front]; }
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
        cout << "Name " << name << " not found in graph!\n";
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
        int v, count;
        char ch;
        for (int i = 0; i < n; i++) {
            temp = head[i];
            cout << "vertex: " << head[i]->name << endl;
            count = 0;
            do {
                current = new node;
                do {
                    cout << "Enter adjacent vertex!\n";
                    cout << "v: ";
                    cin >> v;
                } while (v == i);
                count++;
                current->vertex = v;
                strcpy(current->name, head[v]->name);
                temp->next = current;
                temp = temp->next;
                if (count == n - 1) {
                    cout << "Maximum number of adjacent vertices reached for "
                            "node!"
                         << endl;
                    break;
                }
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
                dfs(head[k]);
            }
            temp = temp->next;
        }
    }

    void dfs_iterative() {
        int v;
        stack s;
        node* temp;
        reset();
        cout << "Enter vertex!" << endl;
        cout << "v: ";
        cin >> v;
        temp = head[v];
        s.push(temp);

        while (!s.isEmpty()) {
            temp = head[s.getTop()->vertex];
            s.pop();

            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                cout << temp->name << "\t";
            }

            temp = temp->next;
            while (temp) {
                if (!visited[temp->vertex]) {
                    s.push(temp);
                }
                temp = temp->next;
            }
        }
    }

    void bfs_iterative() {
        int v;
        queue q;
        node* temp;
        reset();
        cout << "Enter vertex!" << endl;
        cout << "v: ";
        cin >> v;
        temp = head[v];

        q.enqueue(head[v]);

        while (!q.isEmpty()) {
            temp = head[q.getFront()->vertex];
            q.dequeue();

            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                cout << temp->name << " \t";
            }

            temp = temp->next;
            while (temp) {
                if (!visited[temp->vertex]) {
                    q.enqueue(temp);
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    graph g;
    int ch;
    cout << "Enter 1 to create graph" << endl;
    cout << "Enter 2 to display graph" << endl;
    cout << "Enter 3 for recursive dfs traversal" << endl;
    cout << "Enter 4 for iterative dfs traversal" << endl;
    cout << "Enter 5 for iterative bfs traversal" << endl;
    cout << "Enter 0 to exit" << endl;
    cout << "ch :";
    cin >> ch;
    do {
        switch (ch) {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.dfs();
                break;
            case 4:
                g.dfs_iterative();
                break;
            case 5:
                g.bfs_iterative();
                break;
            default:
                cout << "Wrong choice!" << endl;
                break;
        }
        cout << "Enter your choice (0 to exit)!" << endl;
        cout << "ch: ";
        cin >> ch;
    } while (ch != 0);
}