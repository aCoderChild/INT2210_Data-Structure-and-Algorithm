#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	int table[n+1];
	table[0] = 0;
	table[1] = 1;
	for (int i = 2; i <= n; i++) {
		table[i] = table[i-1] + table[i-2];
	}
	return table[n];
}

int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << "The nth number of the fibonacci sequence: ";
	cout << fib(n);
	return 0;
}