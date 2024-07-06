//using linkedlist
// just need a marker: top

#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node *temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    bool pop() {
        if (top == NULL) return false;
        else {
            Node *temp = top;
            top = top->next;
            delete temp;
            return true;
        }
    }

    void print() {
        vector<int> a;
        Node *temp = top;
        while (temp != NULL) {
            a.push_back(temp->data);
            temp = temp->next;
        }
        reverse(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
    }
};

int main() {
    Stack S;
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;
    cin.ignore();  // Ignore the newline character after the number of operations

    for (int i = 0; i < n; ++i) {
        string operation;
        getline(cin, operation);
        if (operation.substr(0, 4) == "push") {
            int x = stoi(operation.substr(5));
            S.push(x);
        } else if (operation == "pop") {
            S.pop();
        }
    }

    S.print();
    return 0;
}
