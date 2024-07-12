#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Student {
    int ID;
    string Name;
    string Class;

    Student() : ID(0), Name(""), Class("") {}
    /*
    When you insert a new element into the unordered_map, it will default-construct 
    a Student object if the key is not already present in the map. 
    However, your Student struct does not have a default constructor 
    (a constructor with no arguments), which is required for this default construction.
    */

    Student(int id, string name, string clss) : ID(id), Name(name), Class(clss) {}
};

class hashMap {
    unordered_map<int, Student> HashMap;

public:
    void Insert(int ID, string Name, string Class) {
        Student toInsert(ID, Name, Class);
        HashMap[ID] = toInsert;
    }

    void Delete(int ID) {
        HashMap.erase(ID);
    }

    bool Infor(int ID) {
        auto it = HashMap.find(ID);
        if (it != HashMap.end()) {
            cout << it->second.Name << ", " << it->second.Class << endl;
            return true;
        }

        cout << "NA, NA" << endl;
        return false;
    }
};

int main() {
    hashMap List;

    string operation;
    while (cin >> operation) {
        if (operation == "Insert") {
            int ID;
            string Name, Class;
            cin >> ID >> Name >> Class;
            List.Insert(ID, Name, Class);
        } else if (operation == "Delete") {
            int ID;
            cin >> ID;
            List.Delete(ID);
        } else {
            int ID;
            cin >> ID;
            List.Infor(ID);
        }
    }

    return 0;
}
