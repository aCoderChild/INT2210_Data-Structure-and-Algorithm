#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int l, int m, int r) {
	int len1 = m - l + 1; // from 0 to m
	int len2 = r - m; // from m+1 to the end

	int arr1[len1], arr2[len2];

	for (int i = 0; i  < len1; i++) {
		arr1[i] = array[l + i];
	}

	for (int i = 0; i < len2; i++) {
		arr2[i] = array[m + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while (i < len1 && j < len2) {
		if (arr1[i] <= arr2[j]) {
			array[k] = arr1[i];
			i++;
		} else {
			array[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < len1) {
		array[k] = arr1[i];
		i++;
		k++;
	}

	while (j < len2) {
		array[k] = arr2[j];
		j++;
		k++;
	}
}

void Merge_Sort(int array[], int l, int r) {
	if (l < r) {
		int m = l + (r - l)/2;
		Merge_Sort(array, l, m);
		Merge_Sort(array, m+1, r);
		merge(array, l, m, r);
	}
}

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

int main()
{
	int arr[] = {6, 5, 12, 10, 9, 1};
	int n = sizeof(arr)/sizeof(arr[0]);

	Merge_Sort(arr, 0, n-1);
	printArray(arr, n-1);
	return 0;
}