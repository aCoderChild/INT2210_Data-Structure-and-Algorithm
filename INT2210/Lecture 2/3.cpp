#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* readNum(int a[], int n) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < n; i++) {
        Node* toInsert = new Node();
        toInsert->data = a[i];
        toInsert->prev = NULL;
        toInsert->next = NULL;

        if (head == NULL) {
            head = toInsert;
            temp = head;
        } else {
            temp->next = toInsert;
            toInsert->prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

int count_triplets(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp!= NULL && temp->next!= NULL && temp->next->next!= NULL) {
        if (temp->data + temp->next->data + temp->next->next->data == 0) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

void deleteList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Node* head = readNum(a, n);
    cout << count_triplets(head) << endl;
    deleteList(head); // Deallocate memory
    return 0;
}

/* Problems with my codes:
The readNum function does not handle the case when the input array has only one element. In this case, the head node is not properly initialized.
The count_triplets function does not check for edge cases, such as an empty list or a list with only one or two elements.
The code does not handle memory deallocation for the dynamically allocated nodes, which can lead to memory leaks.
*/