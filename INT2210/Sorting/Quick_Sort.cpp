#include <bits/stdc++.h>
using namespace std;

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl; // add a newline at the end
}

//PARTITION FUNCTION//
int partition(int a[], int l, int r) {
    int pivot = a[l];
    int left = l + 1;
    int right = r;
    
    while(true) {
        while (left <= right && a[left] <= pivot) left++;
        while (left <= right && a[right] > pivot) right--; // do THIS
        
        if (left > right) break;
        swap(a[left], a[right]);
        left++;
        right--;
    }

    swap(a[l], a[right]);
    return right;
}

//QUICKSORT FUNCTION//
void Quicksort(int a[], int l, int r) {
    if (l < r) {
        int id = partition(a, l, r);
        
        Quicksort(a, l, id - 1);
        Quicksort(a, id + 1, r);
    }
}
