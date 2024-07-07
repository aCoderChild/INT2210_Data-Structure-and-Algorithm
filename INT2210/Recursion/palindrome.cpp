#include <bits/stdc++.h>
using namespace std;

bool isPalindrome (string s) {
	if (s.size() == 0 || s.size() == 1) return true;

	if (s[0] == s[s.size() - 1]) {
		return isPalindrome(s.substr(1, s.size() - 2)); //2nd parameter: length of the sub string
	}

	return false;
	//when s.size() != 0 or 1;
}

int main()
{
	cout << "Enter your string: ";
	string s;
	cin >> s;
	if (isPalindrome(s)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}