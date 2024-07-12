#include <iostream>
#include <vector>
using namespace std;

class Hash {
    vector<vector<int> > a;

    int f(int x) {
        return (2 * x + 5) % 11;
    }

public:
    Hash() : a(11) {}  // Properly initialize the vector of vectors

    void Insert_by_linearProbing(int x) {
        int id = f(x);
        a[id].push_back(x);
    }

    void print() {
        for (int i = 0; i < 11; ++i) {
            for (auto j : a[i]) {
                if (j != 0) cout << j << " ";
            }
            //cout << endl;
        }
    }
};

int main() {
    Hash List;
    List.Insert_by_linearProbing(12);
    List.Insert_by_linearProbing(44);
    List.Insert_by_linearProbing(13);
    List.Insert_by_linearProbing(88);
    List.Insert_by_linearProbing(23);
    List.Insert_by_linearProbing(94);
    List.Insert_by_linearProbing(11);
    List.Insert_by_linearProbing(39);
    List.Insert_by_linearProbing(20);
    List.Insert_by_linearProbing(16);
    List.Insert_by_linearProbing(5);

    List.print();
    return 0;
}
