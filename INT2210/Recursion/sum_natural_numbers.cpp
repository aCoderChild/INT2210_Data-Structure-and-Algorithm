#include <bits/stdc++.h>
using namespace std;

int sum_of_natural_number (int n) {
	if (n == 0) return n;

	return n + sum_of_natural_number(n-1);
}

int main()
{
	cout << "Enter the number: ";
	int n;
	cin >> n;
	cout << sum_of_natural_number(n);
	return 0;
}