#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    int size = 0;
    Node* head = NULL;

    bool Insert(int x, int p) {
        if (p <= 0 || p > size + 1) return false;

        Node* temp = new Node();
        temp->data = x;
        
        if (p == 1) {
            temp->next = head;
            head = temp;
        }

        else {
            Node* temp2 = head;
            for (int i = 0; i < p - 2; i++) {
                temp2 = temp2->next;
            }

            temp->next = temp2->next;
            temp2->next = temp;
        }

        size++;
        return true;
    }

    bool Delete(int p) {
        
        if (p <= 0 || p > size) return false;
        if (p == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        else {
            Node* temp = head;
            for (int i = 0; i < p - 2; i++) {
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;

        return true;
    }

    //Alternative: print the linked list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    //Testing
   Node LinkedList;

   LinkedList.Insert(1,1);
   LinkedList.Insert(3,2);
   LinkedList.Insert(4,2);
   LinkedList.Insert(2,3);
   LinkedList.Delete(2);

   LinkedList.print();
   
   return 0;
}