#include <bits/stdc++.h>
using namespace std;

class Point {
    public:
    double x, y;
};

class Line {
    Point p1, p2;
    double a,b;

    public:
    Line(Point p1, Point p2) {
        a = (p1.y - p2.y) / (p1.x - p2.x);
        b = p1.y - a * p1.x;
    }

    bool hasIntersection(Line& other) {
        if (a == other.a) {
            if (b == other.b) {
                cout << "MANY" << endl;
                return true;
            }

            else {
                cout << "NONE" << endl;
                return false;
            }
        }

        else {
            double x = (b - other.b) / (other.a - a);
            double y = a * x + b;
            cout << x << " " << y << endl;
            return true;
        }
    }
};

int main()
{
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

    Line AB(A, B);
    Line CD(C, D);
    AB.hasIntersection(CD);
    return 0;
}