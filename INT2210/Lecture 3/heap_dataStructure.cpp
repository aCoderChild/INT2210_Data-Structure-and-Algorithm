#include<iostream>
#include<cmath>
using namespace std;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

class MinHeap {
public:
	int* ptr; // pointer to array of the elements int heap
	int capacity; // maximum possible size of minheap
	int heap_size; // current number of elements in minheap

	MinHeap(int cap) {
		heap_size = 0;
		capacity = cap;
		ptr = new int[cap]; // pointer point to the first element of the minheap
		// aka pointer to the array (minHeap) itself
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	int left(int i) {
		return i * 2 + 1;
	}

	int right(int i) {
		return i * 2 + 2;
	}

	bool insertKey(int k) {
		if (heap_size == capacity) {
			cout << "Cant insert the key! FULL!";
			return false;
		}

		heap_size++;
		int i = heap_size - 1;
		ptr[i] = k;

		//Fix the minHeap property is it is violated 
		while (i != 0 && ptr[parent(i)] > ptr[i]) {
			swap(ptr[i], ptr[parent(i)]);
			i = parent(i);
		}
		return true;
	}

	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;

		if (l < heap_size && ptr[smallest] > ptr[l]) smallest = l;
		if (r < heap_size && ptr[smallest] > ptr[r]) smallest = r;

		if (smallest != i) {
			swap(ptr[smallest], ptr[i]);
			heapify(smallest);
		}
	}

	//Function: return the index of the founded value
	int linearSearch(int k) {
		for (int i = 0; i < heap_size; i++) {
			if (ptr[i] ==  k) {
				cout << "Found!" << endl;
				return i;
			}
		}

		cout << "Not Found!" << endl;
		return -1;
	}

	void deleteKey(int k) {
		int i = linearSearch(k);
		while (left(i) < heap_size && right(i) < heap_size) {
			if (ptr[left(i)] < ptr[right(i)]) {
				ptr[i] = ptr[left(i)];
				i = left(i);
			}

			else {
				ptr[i] = ptr[right(i)];
				i = right(i);
			}
		}

		if (left(i) < heap_size && ptr[left(i)] < ptr[i]) {
			ptr[i] = ptr[left(i)];
		}

		ptr[i] = 0;
	}

	int extractMin() {
		return ptr[0];
	}

	int extractMax() {
		int result = ptr[0];
		for (int i = 0; i < heap_size; i++) {
			if (result < ptr[i]) result = ptr[i];
		}
		return result;
	}

	void print() {
		for (int i = 0; i < heap_size; i++) {
			if (ptr[i] != 0) cout << ptr[i] << " ";
		}
	}
};

int main()
{
	MinHeap List(10);
	List.insertKey(10);
	List.insertKey(5);
	List.insertKey(3);
	List.insertKey(2);
	List.insertKey(4);
	List.insertKey(1);
	List.insertKey(6);
	List.insertKey(7);

	cout << "List before heapify: ";
	List.print();
	cout << endl;

	List.heapify(4);

	cout << "List after heaify: ";
	List.print();

	cout << endl;
	cout << "Min: " << List.extractMin() << endl;
	cout << "Max: " << List.extractMax() << endl;
}

//This is the heap of >0 intergers
