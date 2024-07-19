//Problem: power sum - 10 = 1^2 + 3^2

//Idea: iterate through all the number starting from 1
//for every num we recursively try all greater numbers 
//if we are able to find a sum, Increase the result

#include <bits/stdc++.h>
using namespace std;

//find the power of a number recursively
int power(int num, int n) {
	if (n == 0) return 1;
	if(n % 2 == 0) {
		return power(num, n/2) * power(num, n/2);
	}
	return num * power(num, n/2) * power(num, n/2);
}

int check(int x, int n, int current = 1, int current_sum = 0) {
	//Initialise the number of ways to express
	int result = 0;

	int p = power(current, n);
	while(p + current_sum < x) {
		//Recursively check all greater values of i
		result += check(x, n, current + 1, p + current_sum);
		current++;
		p = power(current, n);
	}

	if (p + current_sum == x) result++;
	return result;
}

int main()
{
	int x = 10, n = 2;
	cout << check(x, n);
}

//analyse: 