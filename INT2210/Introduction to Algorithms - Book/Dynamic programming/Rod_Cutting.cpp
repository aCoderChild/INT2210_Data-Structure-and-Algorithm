/*
Given the rod of length n inches and a table of prices pi for i = 1,2,..,n
Determine the maximum revenue rn obtainable by cutting up the rod and selling
the pieces. If the price pn for a rod of length n is large enough, an optimal
solution might require no cutting at all
*/

//rn = max{pi+r(n-i): 1 <= i <= n}
//r: the total expense


//recursive Top - down implementation
// From Big Problem to smaller
/*
#include <bits/stdc++.h>
using namespace std;

int Cut_Rod(int p[], int n) {
	if (n == 0) return 0;
	int q = numeric_limits<int>::min();
	for (int i = 1; i <= n; i++) {
		q = max(q, p[i] + Cut_Rod(p, n-i));
	}
	return q;
}

int main() {
	int n;
	cin >> n;
	int p[n + 1];
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	int l;
	cin >> l;
	cout << Cut_Rod(p, l);
}
*/

//Bottom - up implementation
//From Small problem to BigOne
/*
#include <bits/stdc++.h>
using namespace std;

int Bottom_Up_Cut_Rod(int p[], int n) {
	int r[n+1]; //table to REMEMBER the SOLUTIONS
	r[0] = 0;
	for (int i = 1; i <= n; i++) {
		int q = numeric_limits<int>::min(); //inside the loop
		for (int j = 1; j <= i; j++) { // contain i = j+0
			q = max(q, p[j] + p[i-j]);
			r[j] = q;
		}
	}
	return r[n];
}

int main() {
	int n;
	cin >> n;
	int p[n + 1];
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	int l;
	cin >> l;
	cout << Bottom_Up_Cut_Rod(p, l);
}
*/

//SUBPROBLEM GRAPHS
/*
You can think of the recursion tree for the top-down recursive method
with all nodes for the same subproblems coalisced into a 
single vertex and all edges directed from parent to child
*/

//Problem with my code
//The function Extened_Bottom_Up_Cut_Rod returns a pointer to a local array s, 
//which is not valid after the function returns.

#include <bits/stdc++.h>
using namespace std;

void Extened_Bottom_Up_Cut_Rod(int p[], int n, int* r, int* s) {
    r[0] = 0;
    s[0] = 0;

    for (int i = 1; i <= n; i++) {
        int q = numeric_limits<int>::min();
        for (int j = 1; j <= i; j++) { //cover i = i + 0
            if (q < p[j] + r[i-j]) {
                s[i] = j; //the value is only updated when a better cut is found
                q = p[j] + r[i-j];
            }
        }
        r[i] = q;
    }
}

int main() {
    int n;
    cin >> n;
    int p[n + 1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int l;
    cin >> l;
    int r[l+1], s[l+1];
    Extened_Bottom_Up_Cut_Rod(p, l, r, s);
    for (int i = 1; i <= l; i++) {
        cout << s[i] << " ";
    }
    return 0;
}