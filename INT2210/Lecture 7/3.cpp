#include <iostream>
using namespace std;

void swap(int&a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b) << endl;
	return 0;
}