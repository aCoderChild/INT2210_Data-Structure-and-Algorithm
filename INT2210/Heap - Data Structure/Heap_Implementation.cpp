//Max - Heap
//Max - Heap
#include <bits/stdc++.h>
using namespace std;

#define C 10000

void Heapify(int Heap[], int i, int n) {
    int largest = i;
    int leftChild = i * 2 + 1;
    int rightChild = i * 2 + 2;
    if (leftChild < n && Heap[leftChild] > Heap[largest]) {
        largest = leftChild;
    }
    if (rightChild < n && Heap[rightChild] > Heap[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(Heap[largest], Heap[i]);
        Heapify(Heap, largest, n);
    }
}

void Build_Heap(int Heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(Heap, i, n);
    }
}

//Heap_Push - Bottom up
void Heap_Push(int Heap[], int n, int value) {
	Heap[n] = value;
	int i = n;
	while (i > 0 && Heap[i] > Heap[i/2]) {
		swap(Heap[i], Heap[i/2]);
		i = i/2;
	}
}

//Heap Pop = Extract max
void Heap_Pop(int Heap[], int &n) {
    swap(Heap[0], Heap[n - 1]);
    n--;
    Heapify(Heap, 0, n);
}

void Print_Heap(int Heap[], int n) {
    for (int i = 0; i < n; i++) {
        cout << Heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    int heap[C];
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> heap[i];
    }
    Build_Heap(heap, n);
    /*
    cout << "Heap before Heap pop operation: ";
    Print_Heap(heap, n);
    Heap_Pop(heap, n);
    cout << "Heap after Heap pop operation: ";
    Print_Heap(heap, n);
    */

    cout << "Heap before Heap push operation: ";
    Print_Heap(heap, n);
    Heap_Push(heap, n, 50);
    cout << "Heap after Heap push operation: ";
    Print_Heap(heap, n+1);

}