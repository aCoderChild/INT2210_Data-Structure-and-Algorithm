#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoi (int n, char a = 'a', char b = 'b', char c = 'c') {
	if (n == 0) return;

	tower_of_hanoi(n-1, a, c, b);
	cout << "Move disk " << n << " from rod " << a << " to rod " << b << endl;
	tower_of_hanoi(n-1, c, b, a);
}

int main()
{
	cout << "Enter the number of disks: ";
	int n;
	cin >> n;

	tower_of_hanoi(n);
}

//algorithm: what is called first solved first