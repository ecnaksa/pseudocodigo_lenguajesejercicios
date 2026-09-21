/* Ejercicio 1 - Vector2D con -, y * por escalar. */
#include <iostream>
using namespace std;

class Vector2D {
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
    Vector2D operator-(const Vector2D &o) const { return Vector2D(x - o.x, y - o.y); }
    Vector2D operator*(double k) const { return Vector2D(x * k, y * k); }
    friend ostream& operator<<(ostream &os, const Vector2D &v);
};

ostream& operator<<(ostream &os, const Vector2D &v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector2D a(5, 7), b(2, 3);
    cout << "a - b = " << (a - b) << endl;   // (3, 4)
    cout << "a * 2 = " << (a * 2.0) << endl; // (10, 14)
    return 0;
}
