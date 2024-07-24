// C++ program for implementation of Heap Sort

/*
#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);

    cout << "Sorted array is \n";
    printArray(arr, N);
}
*/
#include <bits/stdc++.h>
using namespace std;

void heapify(int Heap[], int i, int n) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && Heap[leftChild] > Heap[largest]) { //compare to the largest index
        largest = leftChild;
    }

    if (rightChild < n && Heap[rightChild] > Heap[largest]) {
        largest = rightChild;
    }

    if (largest != i) {
        swap(Heap[i], Heap[largest]);
        heapify(Heap, largest, n);
    }
}

void buildHeap(int Heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(Heap, i, n);
    }
}

void heapSort(int Heap[], int n) {
    buildHeap(Heap, n);
    for (int i = n - 1; i > 0; i--) {
        swap(Heap[0], Heap[i]);
        heapify(Heap, 0, i);
    }
}

void printHeap(int Heap[], int n) {
    for (int i = 0; i < n; i++) {
        cout << Heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int heap[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(heap) / sizeof(heap[0]);

    heapSort(heap, n);
    printHeap(heap, n);

    return 0;
}
