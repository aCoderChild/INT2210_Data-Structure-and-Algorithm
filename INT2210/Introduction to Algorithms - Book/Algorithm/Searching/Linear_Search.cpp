/*
pseudocode:
	procedure LinearSearch (int A[], int value):
		for int j = 1 to A.length:
			if A[j] == value:
				return A[j]
				STOP
		return -1 (NOT FOUND) 
*/

//code
#include<iostream>
using namespace std;

void Linear_Search(int A[], int n, int value) {
	for (int i = 0; i < n; i ++) {
		if (A[i] == value) {
			cout << "Index: " << i + 1 << endl;
			return;
		}
	}

	cout << "Not Found!" << endl;
	return;
}

int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	int a[n];
	cout << "Enter the array: ";
	for (int i = 0; i < n; i++) cin >> a[i];
		
	cout << "Enter the value: ";
	int value;
	cin >> value;
	Linear_Search(a, n, value);
}