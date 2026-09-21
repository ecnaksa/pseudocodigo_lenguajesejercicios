/*
 * Fraccion: sobrecarga de * y << (multiplicacion de fracciones).
 */
#include <iostream>
using namespace std;

class Fraccion {
    int num, den;
public:
    Fraccion(int n = 0, int d = 1) : num(n), den(d) {}

    Fraccion operator*(const Fraccion &o) const {
        return Fraccion(num * o.num, den * o.den);
    }
    friend ostream& operator<<(ostream &os, const Fraccion &f);
};

ostream& operator<<(ostream &os, const Fraccion &f) {
    os << f.num << "/" << f.den;
    return os;
}

int main() {
    Fraccion a(1, 2), b(2, 3);
    cout << a << " * " << b << " = " << (a * b) << endl;   // 1/2 * 2/3 = 2/6
    return 0;
}
