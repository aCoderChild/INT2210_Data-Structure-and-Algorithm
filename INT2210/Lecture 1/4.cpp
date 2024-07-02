#include <bits/stdc++.h>
using namespace std;

void quickSort(int a[], int l, int r) {
    int p = a[(l + r) / 2];
    int i = l, j = r;

    while (i < j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }

        if (i < r) quickSort(a, i, r);
        if (l < j) quickSort(a, l, j);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) swap(a[i], a[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    */

    quickSort(a, 0, n-1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    return 0;
}