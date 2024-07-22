/*
write a function fib(n) that takes in a number as an argument
the function should return the nth number of the Fibonacci sequence
*/

/*
#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
	if (n == 0) return 0;
	if (n <= 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << "The nth number of the Fibonacci sequence is: ";
	cout << fib(n) << endl;
	return 0;
}
*/

//Analyse: when n is large => the process pretty SLOW
// => WHY WE NEED DYNAMIC PROGRAMMING


//Memoization
// use an ARRAY or a MAP to store values and keys

#include <bits/stdc++.h>
using namespace std;

int fib(int n, map<int, int>& num) {
	if (num.find(n) != num.end()) return num[n]; //a map to store the answers
	if (n == 0) {
		num[n] = 0;
	}
	else if (n <= 2) {
		num[n] = 1;
	}
	else {
		num[n] = fib(n-1, num) + fib(n-2, num);
	}
	return num[n];
}

int main()
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	cout << "The nth number of the Fibonacci sequence is: ";
	map<int, int> num;
	cout << fib(n, num) << endl;
	return 0;
}