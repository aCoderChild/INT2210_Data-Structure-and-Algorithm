#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int a[], int left, int right, int k) {

	if (left > right) return false;
	
	int mid = (left+right) / 2;
	if (a[mid] == k) return true;

	if (a[mid] < k) return binarySearch(a, mid + 1, right, k);
	return binarySearch(a, left, mid - 1, k);
}

int main()
{
	cout << "Enter the number: ";
	int n;
	cin >> n;

	cout << "Enter the array: ";
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << "Enter the search number: ";
	int k;
	cin >> k;

	if (binarySearch(a, 0, n-1, k)) cout << "YES";
	else cout << "NO";

	return 0;
}