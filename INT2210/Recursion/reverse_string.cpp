#include <bits/stdc++.h>
using namespace std;

string reverse_string(string s) {
	if (s == "") return s;
	string s1 = s.substr(1);
	return reverse_string(s1) + s[0];
}

int main()
{
	cout << "Enter your string: ";
	string s;
	cin >> s;
	cout << reverse_string(s) << endl;
	return 0;
}