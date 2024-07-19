//SELECTION SORT
#include <bits/stdc++.h>
using namespace std;

void Selection_Sort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_id = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min_id]) min_id = j; //should be min_id
		}

		if (min_id != i) swap(a[i], a[min_id]);
	}
}

int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << "Enter the array: ";
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	Selection_Sort(a, n);
	cout << "Array after sorting: ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}