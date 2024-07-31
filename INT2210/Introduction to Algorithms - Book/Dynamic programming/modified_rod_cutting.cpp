/*
#include <bits/stdc++.h>
using namespace std;

int BOTTOM_UP_CUTTING_ROD (int t[], int n) {
	int r[n+1];
	r[0] = 0;
	for (int i = 1; i <= n; i++) {
		int q = numeric_limits<int>::min();
		for (int j = 1; j <= i; j++) {
			q = max(q, p[j] + r[i-j]);
		}
		r[j] = q;
	}
	return r[n];	
}

int main()
{
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; i++) {
		int p, c;
		cin >> p >> c;
		t[i] = p - c;
	}

	int l;
	cout << BOTTOM_UP_CUTTING_ROD(t, l);
}
*/
//What I'm understanding: every cut has different Cost