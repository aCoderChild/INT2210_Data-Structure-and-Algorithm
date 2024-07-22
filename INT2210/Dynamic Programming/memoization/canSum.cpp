/* write a function canSum(targetSum, numbers) that takes in a target sum and 
an array of numbers as argument
the function should return a boolean indicating whether or not it is possible to
generate the targetSum using numbers from the array
You may use an element of the array as many times as possible
You may assume that all unput numbers are nonnegative
*/

/* MY CODE - still efficient to some extent
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> num) {
	int Min = num[0];
	for (auto i : num) {
		if (i < Min) Min = i;
	}
	return Min;
}

// fk this function, got right idea but wrong implementation
bool canSum(int targetSum,vector<int> numbers, map<int, bool>& check) {
	int Min = findMin(numbers);
	if (targetSum < Min) {
		check[targetSum] = false;
	} else if (find(numbers.begin(), numbers.end(), targetSum) != numbers.end()) {
		check[targetSum] = true;
	} else {
		for (auto i : numbers) {
			check[targetSum] = canSum(targetSum - i, numbers, check);
			if (check[targetSum] == true) break;
		}
	}
	return check[targetSum];
}

int main()
{
	cout << "Enter the target Sum: ";
	int targetSum;
	cin >> targetSum;

	cout << "Enter the numbers: ";
	vector<int> numbers;
	int x;
	while (cin >> x) {
		if (x >= 0) numbers.push_back(x);
		else break;
	}

	map<int, bool> check;
	cout << "Is the sum can: ";
	if (canSum(targetSum, numbers, check)) cout << "YES";
	else cout << "NO";
	return 0;
}
*/

//AI
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int findMin(const vector<int>& num) {
    return *min_element(num.begin(), num.end());
}

bool canSum(int targetSum, const vector<int>& numbers, map<int, bool>& memo) {
    if (memo.find(targetSum)!= memo.end()) return memo[targetSum];
    if (targetSum < 0) return false;
    if (targetSum == 0) return true; //Base case
    for (int num : numbers) {
        if (canSum(targetSum - num, numbers, memo)) {
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}

int main() {
    cout << "Enter the target Sum: ";
    int targetSum;
    cin >> targetSum;

    cout << "Enter the numbers: ";
    vector<int> numbers;
    int x;
    while (cin >> x) {
        if (x >= 0) numbers.push_back(x);
        else break;
    }

    map<int, bool> memo;
    cout << "Is the sum can: ";
    if (canSum(targetSum, numbers, memo)) cout << "YES";
    else cout << "NO";
    return 0;
}