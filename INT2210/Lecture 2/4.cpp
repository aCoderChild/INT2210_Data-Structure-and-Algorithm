//using linkedlist
//insert at tail and delete at head => complexity O(1)

/*
#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int x) {
        Node* toEnqueue = new Node();
        toEnqueue->data = x;
        toEnqueue->next = NULL;

        if (head == NULL) {
            head = toEnqueue;
            tail = toEnqueue;
        } else {
            tail->next = toEnqueue;
            tail = toEnqueue;
        }
    }

    bool dequeue() {
        if (head == NULL) return false;
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == NULL) {
                tail = NULL; // If the queue is empty after dequeue, set tail to NULL
            }
            return true;
        }
    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;
    cin.ignore();  // Ignore the newline character after the number of operations
    for (int i = 0; i < n; ++i) {
        string operation;
        getline(cin, operation);
        if (operation.substr(0, 7) == "enqueue") {
            int x = stoi(operation.substr(8));
            q.enqueue(x);
        } else if (operation == "dequeue") {
            q.dequeue();
        }
    }
    q.print();
    return 0;
}
*/

//using array
#include <bits/stdc++.h>
using namespace std;

class Queue {
    vector<int> queue;

    public:
    void enqueue(int x) {
        queue.push_back(x);
    }

    bool dequeue() {
        if (queue.empty()) {
            return false;
        }

        queue.erase(queue.begin());
        return true;
    }

    void print() {
        for (int i = 0; i < queue.size(); ++i) {
            cout << queue[i] << " ";
        }
    }
};

int main()
{
    Queue Q;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string operation;
        getline(cin, operation);
        if (operation.substr(0, 7) == "enqueue") {
            int x = stoi(operation.substr(8));
            Q.enqueue(x);
        }

        else if (operation == "dequeue") {
            Q.dequeue();
        }
    }
    Q.print();

    return 0;
}