#include <bits/stdc++.h>
using namespace std;

string toBinary (int n, string res) {
	if (n == 0) {
		return res;
	}

	res = to_string(n%2) + res;
	return toBinary(n/2, res);
}

int main()
{
	cout << "Enter your number: ";
	int n;
	cin >> n;
	cout << toBinary(n, "");
	return 0;
}