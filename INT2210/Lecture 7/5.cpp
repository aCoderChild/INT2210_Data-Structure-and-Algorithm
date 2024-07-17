/*
#include <bits/stdc++.h>
using namespace std;

void permutations(vector<char> a, string current = "") {
	if (a.empty()) cout << current << endl;
	else {
		for (int i = 0; i < (int)a.size(); i++) {
			char c = a[i];
			vector<char> newVec = a;
			newVec.erase(newVec.begin() + i);
			permutations(newVec, current + c);
		}
	}
}

vector<char> Vector_Form (int n) {
	vector<char> result;
	for (int i = 1; i <= n; i++) {
		result.push_back((char)(i+'0'));
	}
	return result;
}

int main()
{
	cout << "Enter the number: ";
	int n;
	cin >> n;
	vector<char> String = Vector_Form(n);
	cout << "The string is: ";
	for (auto i : String) cout << i << " ";
	cout << endl;
	
	cout << "All the permutations: " << endl;
	permutations(String);
	return 0;
}
*/

//BACK TRACKING

