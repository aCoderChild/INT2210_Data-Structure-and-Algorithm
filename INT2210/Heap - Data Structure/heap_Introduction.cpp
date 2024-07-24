/*
Min Heap: 
	Insert(element) -> O(logN)
	Search(element) -> O(N)
	Find_Min() -> O(1)
	Delete_Min() -> O(logN)

Tree concept of heap: A tree can be represented in the form 
of an ARRAY
	Parent -> i
	leftChild -> 2i+1
	rightChild ->2i+2

	child -> i
	parent i/2

Heap is a complete binary tree and be stored in an ARRAY

Max array size = 2^(h+1) - 1

Max nodes at ht h = 2^h

-------------------------------

range of leaves: from n/2 to n-1
range of eternal leaves: from 0 to n/2-1

*/

#define C 10000

#include <bits/stdc++.h>
using namespace std;

class Max_Heap {
    int n;
    int* Heap; //initialise

    int l(int i) {
        return i * 2 + 1;
    }

    int r(int i) {
        return i * 2 + 2;
    }

    int p(int i) {
    	return i/2;
    }

public:
    Max_Heap(int N, int H[]) : n(N) {
        Heap = new int[C];
        for (int i = 0; i < N; i++) {
            Heap[i] = H[i];
        }
    }

    ~Max_Heap() {
        delete[] Heap;
    }

    //top - down
    void Heapify(int i) {
        int largest = i;
        int L = l(i);
        int R = r(i);

        if (L < n && Heap[L] > Heap[largest]) {
            largest = L;
        }

        if (R < n && Heap[R] > Heap[largest]) {
            largest = R;
        }

        if (largest != i) {
            swap(Heap[i], Heap[largest]);
            Heapify(largest);
        }
    }

    //Bottom - up order
    void BuildHeap() {
        for (int i = n/2-1; i >= 0; i--) {
            Heapify(i);
        }
    }

    void PrintHeap() {
    	for (int i = 0; i < n; i++) {
    		cout << Heap[i] << " ";
    	}
    }

//Heap algorithms--------------------------
    int ExtractMax() {
    	if (n == 0) return -1;
    	int max = Heap[0]; //save the max_value;
    	swap(Heap[0], Heap[n-1]); //swap the max and the last element of the heap
    	n -= 1;
    	Heapify(0); //top - down order (because swap last element to the start)
    	return max;
   }

   //Bottom - up
   void IncreaseKey(int i, int key) {
   		if (key < Heap[i]) return;
   		Heap[i] = key;
   		while (i > 0 && Heap[i/2] < Heap[i]) {
   			swap(Heap[i/2], Heap[i]);
   			i = i/2;
   		}
   }

   void DecreaseKey(int i, int key) {
   		if (key > Heap[i]) return;
   		Heap[i] = key;
   		Heapify(i);
   }

   void InsertElement(int value) {
   		Heap[n] = value;
   		int i = n;
   		while (i > 0 && Heap[i] > Heap[i/2]) {
   			swap(Heap[i], Heap[i/2]);
   			i = i/2;
   		}
   }

   //Prerequisite: heapify, build heap operations
   //Ascending order => MAX HEAP
   void HeapSort() {
   	for (int i = n-1; i > 0; i--) {
   		swap(Heap[0], Heap[i]);
   		Heapify(0);
   	}
   }
};

int main() {
    cout << "the number of elements: ";
    int n;
    cin >> n;
    cout << "Enter the elements: ";
    int arr[n];
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    //Build Heap(from scratch)
    Max_Heap heap(n, arr);
    heap.BuildHeap(); //bottom - up operation
    cout << "The heap is: ";
    heap.PrintHeap();
    cout << endl;

    /*
    //Extract Opertion
    cout << "Extract Max Operation: ";
    cout << heap.ExtractMax() << endl;

    cout << "the heap after extract max Operation: ";
    heap.PrintHeap();
    cout << endl;

    //Increase key
    cout << "Enter the index and the key you want to increase: ";
    int i, key;
    cin >> i >> key;
    cout << "Increase Key Operation: ";
    heap.IncreaseKey(i, key);
    cout << "the heap after increase key operation: ";
    heap.PrintHeap();
    cout << endl;

    //Decrease key
    cout << "Enter the index and the key you want to decrease: ";
    int i1, key1;
    cin >> i1 >> key1;
    cout << "Decrase Key Operation: ";
    heap.DecreaseKey(i1, key1);
    cout << "the heap after decrease operation: ";
    heap.PrintHeap();
    cout << endl;

    //Insert element
    cout << "Enter the element to insert: ";
    int num;
    cin >> num;
    heap.InsertElement(num);
    cout << "the heap after inserting element operation: ";
    heap.PrintHeap();
    cout << endl;
    */

    //Heap sort
    cout << "The heap after sorting: ";
    heap.HeapSort();
    heap.PrintHeap();

    return 0;
}

//if you want to go up => use while loop
//if you want to go down => heapify