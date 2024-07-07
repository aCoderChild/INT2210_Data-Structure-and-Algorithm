#include <iostream>
using namespace std;

void swap (int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition (int a[], int left, int right) {
	int k = a[left];

	int l = left + 1;
	int r = right;

	while (true) {
		if (l <= r && a[l] <= k) l++;
		if (l <= r && a[r] > k) r--;

		if (l > r) break;
		swap(a[l], a[r]);
		l++;
		r--;
	}

	swap(a[left], a[r]);
	return r;
}

void quickSort (int a[], int left, int right) {
	if (left < right) {
		int k = partition(a, left, right);
		quickSort(a, left, k - 1);
		quickSort(a, k + 1, right);
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
    quickSort(a, 0, n - 1);
    
    cout << "The array after sorting: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    return 0;
}
