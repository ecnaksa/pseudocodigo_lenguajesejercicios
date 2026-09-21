/*
 * Sobrecarga de +, == y << para una clase Vector2D.
 */
#include <iostream>
using namespace std;

class Vector2D {
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &o) const {
        return Vector2D(x + o.x, y + o.y);
    }
    bool operator==(const Vector2D &o) const {
        return x == o.x && y == o.y;
    }
    friend ostream& operator<<(ostream &os, const Vector2D &v);
};

ostream& operator<<(ostream &os, const Vector2D &v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector2D a(1, 2), b(3, 4);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;               // (4, 6)
    cout << "a == b: " << (a == b ? "si" : "no") << endl; // no
    return 0;
}
