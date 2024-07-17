/*
//QUICK_SORT

#include <iostream>
using namespace std;

//SWAP FUNCTION//
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//PARTITION FUNCTION//
int partition(int a[], int l, int r) {
    int pivot = a[l];
    int left = l + 1;
    int right = r;
    
    while(true) {
        while (left <= right && a[left] <= pivot) left++;
        while (left <= right && a[right] > pivot) right--;
        
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

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    
    int a[n];
    
    cout << "The array: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    Quicksort(a, 0, n - 1);
    
    cout << "The array after sorting: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    return 0;
}
*/

/*
//INSERTION_SORT
#include <bits/stdc++.h>
using namespace std;

void Selection_Sort(int a[], int n) {
    int min_id;
    for (int i = 0; i < n-1; i++) {
        min_id = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_id]) min_id = j;
        }

        if (min_id != i) swap(a[min_id], a[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    Selection_Sort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
*/

//MERGE_SORT
/*
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[left+i];
    for (int i = 0; i < n2; i++) R[i] = a[mid+1+i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void Merge_Sort(vector<int>& a, int left, int right) {
    if (left < right) {
        int mid = (left + right)/2;
        Merge_Sort(a, left, mid);
        Merge_Sort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    Merge_Sort(a, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
*/

//SELECTION_SORT
#include <bits/stdc++.h>
using namespace std;


