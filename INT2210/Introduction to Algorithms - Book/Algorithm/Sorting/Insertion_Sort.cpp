/*
Insertion Sort: 
	Input: A sequence of n numbers (a1, a2, ..., an)
	Output: An increasing or decreasing order of the sequence
*/

#include <iostream>
using namespace std;

void Insertion_Sort_Increasing(int a[], int n) {
    for (int j = 1; j < n; j++) {
        int key = a[j];
        int i = j - 1;
        // Shift elements of a[0..i] that are greater than key to one position ahead
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

void Insertion_Sort_Decreasing(int a[], int n) {
	for (int j = 1; j < n; j++) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] < key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Insertion_Sort_Increasing(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    Insertion_Sort_Decreasing(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

/*
Loop invariant:
	- Initialisation: TRUE prior to the FIRST iteration of the loop
	- Maintenance: If it is true before ann iteration of the loop, it remains true 
	before the next iteration
	- Termination: Whne the loop terminates, the invariant gives us a useful property
	that helps show that the algorithm is correct
*/
