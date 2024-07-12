#include <bits/stdc++.h>
using namespace std;

class Hash {
	int a[11] = {0};

	int f(int x) {
		return (2 * x + 5) % 11;
	}

public:
	void Insert_by_chaining(int x, int i) {
		int id = (f(x) + i) % 11;

		if(a[id] != 0) {
			i++;
			Insert_by_chaining(x, i);
		}

		else {
			a[id] = x;
		}
	}

	void print() {
		for (int i = 0; i < 11; i++) {
			cout << a[i] << " ";
		}
	}
};

int main()
{
	Hash List;
	List.Insert_by_chaining(12, 0);
	List.Insert_by_chaining(44, 0);
	List.Insert_by_chaining(13, 0);
	List.Insert_by_chaining(88, 0);
	List.Insert_by_chaining(23, 0);
	List.Insert_by_chaining(94, 0);
	List.Insert_by_chaining(11, 0);
	List.Insert_by_chaining(39, 0);
	List.Insert_by_chaining(20, 0);
	List.Insert_by_chaining(16, 0);
	List.Insert_by_chaining(5, 0);

	List.print();
}